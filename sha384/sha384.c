/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:22:03 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 17:03:08 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			*sha384(char *file_name, char *str)
{
	uint64_t		*m;
	uint64_t		*w;
	t_sha384_hash	hash;
	t_sha384_hash	base;
	int8_t			fd;

	base = sha384_h_init();
	fd = 0;
	if (!str && file_name && (fd = open(file_name, O_RDONLY)) < 0)
		return (NULL);
	while ((m = (str ? get_str_chunk_l(str, 1) : get_chunk_l(fd, 1))))
	{
		w = sha384_w_init(m);
		hash = base;
		hash = sha384_loop(hash, w);
		base = sha384_base_set(base, hash);
		free(m);
		free(w);
	}
	if (fd != 0)
		close(fd);
	return (digest_sha384(base));
}

t_sha384_hash	sha384_loop(t_sha384_hash hash, uint64_t *w)
{
	int				i;
	uint64_t		s;
	uint64_t		ch;
	uint64_t		temp1;
	uint64_t		temp2;

	i = -1;
	while (++i < 80)
	{
		s = BIT_RR64(hash.e, 14) ^ BIT_RR64(hash.e, 18) ^ BIT_RR64(hash.e, 41);
		ch = (hash.e & hash.f) ^ ((~hash.e) & hash.g);
		temp1 = hash.h + s + ch + g_sha384_k[i] + w[i];
		s = BIT_RR64(hash.a, 28) ^ BIT_RR64(hash.a, 34) ^ BIT_RR64(hash.a, 39);
		ch = (hash.a & hash.b) ^ (hash.a & hash.c) ^ (hash.b & hash.c);
		temp2 = s + ch;
		hash = sha384_hash_cycle(hash, temp1, temp2);
	}
	return (hash);
}

t_sha384_hash	sha384_hash_cycle(t_sha384_hash hash,
								uint64_t temp1, uint64_t temp2)
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

t_sha384_hash	sha384_base_set(t_sha384_hash base, t_sha384_hash hash)
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

uint64_t		*digest_sha384(t_sha384_hash base)
{
	uint64_t		*digest;

	digest = ft_memalloc(sizeof(uint64_t) * 6);
	ft_memcpy(&digest[0], &base.a, 8);
	ft_memcpy(&digest[1], &base.b, 8);
	ft_memcpy(&digest[2], &base.c, 8);
	ft_memcpy(&digest[3], &base.d, 8);
	ft_memcpy(&digest[4], &base.e, 8);
	ft_memcpy(&digest[5], &base.f, 8);
	ft_swapnendian64(digest, 6);
	return (digest);
}
