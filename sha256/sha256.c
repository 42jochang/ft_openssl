/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:22:03 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 17:04:58 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			*sha256(char *file_name, char *str)
{
	uint32_t		*m;
	uint32_t		*w;
	t_sha256_hash	hash;
	t_sha256_hash	base;
	int				fd;

	base = sha256_h_init();
	fd = 0;
	if (!str && file_name && (fd = open(file_name, O_RDONLY)) < 0)
		return (NULL);
	while ((m = (str ? get_str_chunk(str, 1) : get_chunk(fd, 1))))
	{
		w = sha256_w_init(m);
		hash = base;
		hash = sha256_loop(hash, w);
		base = sha256_base_set(base, hash);
		free(m);
		free(w);
	}
	if (fd != 0)
		close(fd);
	return (digest_sha256(base));
}

t_sha256_hash	sha256_loop(t_sha256_hash hash, uint32_t *w)
{
	int				i;
	uint32_t		s;
	uint32_t		ch;
	uint32_t		temp1;
	uint32_t		temp2;

	i = -1;
	while (++i < 64)
	{
		s = BIT_RR32(hash.e, 6) ^ BIT_RR32(hash.e, 11) ^ BIT_RR32(hash.e, 25);
		ch = (hash.e & hash.f) ^ ((~hash.e) & hash.g);
		temp1 = hash.h + s + ch + g_sha256_k[i] + w[i];
		s = BIT_RR32(hash.a, 2) ^ BIT_RR32(hash.a, 13) ^ BIT_RR32(hash.a, 22);
		ch = (hash.a & hash.b) ^ (hash.a & hash.c) ^ (hash.b & hash.c);
		temp2 = s + ch;
		hash = sha256_hash_cycle(hash, temp1, temp2);
	}
	return (hash);
}

t_sha256_hash	sha256_hash_cycle(t_sha256_hash hash,
								uint32_t temp1, uint32_t temp2)
{
	hash.h = hash.g;
	hash.g = hash.f;
	hash.f = hash.e;
	hash.e = hash.d + temp1;
	hash.d = hash.c;
	hash.c = hash.b;
	hash.b = hash.a;
	hash.a = temp1 + temp2;
	return (hash);
}

t_sha256_hash	sha256_base_set(t_sha256_hash base, t_sha256_hash hash)
{
	base.a = base.a + hash.a;
	base.b = base.b + hash.b;
	base.c = base.c + hash.c;
	base.d = base.d + hash.d;
	base.e = base.e + hash.e;
	base.f = base.f + hash.f;
	base.g = base.g + hash.g;
	base.h = base.h + hash.h;
	return (base);
}

uint32_t		*digest_sha256(t_sha256_hash base)
{
	uint32_t		*digest;

	digest = ft_memalloc(sizeof(uint32_t) * 8);
	ft_memcpy(&digest[0], &base.a, 4);
	ft_memcpy(&digest[1], &base.b, 4);
	ft_memcpy(&digest[2], &base.c, 4);
	ft_memcpy(&digest[3], &base.d, 4);
	ft_memcpy(&digest[4], &base.e, 4);
	ft_memcpy(&digest[5], &base.f, 4);
	ft_memcpy(&digest[6], &base.g, 4);
	ft_memcpy(&digest[7], &base.h, 4);
	digest = ft_swapnendian(digest, 8);
	return (digest);
}
