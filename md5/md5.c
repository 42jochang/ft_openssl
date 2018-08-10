/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:06:32 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 16:07:54 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		*md5(char *file_name, char *str)
{
	uint32_t	*m;
	t_hash		hash;
	t_hash		base;
	int			fd;

	base = h_init();
	fd = 0;
	if (!str && file_name && (fd = open(file_name, O_RDONLY)) < 0)
		return (NULL);
	while ((m = (str ? get_str_chunk(str, 0) : get_chunk(fd, 0))))
	{
		hash = base;
		hash = md5_loop(hash, m);
		base = base_set(base, hash);
		free(m);
	}
	if (fd != 0)
		close(fd);
	return (digest_md5(base));
}

t_hash		md5_loop(t_hash hash, uint32_t *m)
{
	uint32_t	k;
	uint32_t	f;
	uint32_t	g;

	k = 0;
	while (k < 64)
	{
		if (k <= 31)
		{
			f = (k <= 15 ? (hash.b & hash.c) | ((~hash.b) & hash.d) :
				(hash.d & hash.b) | ((~hash.d) & hash.c));
			g = (k <= 15 ? k : ((k << 2) + k + 1) % 16);
		}
		else
		{
			f = (k <= 47 ? (hash.b ^ hash.c ^ hash.d) :
				(hash.c ^ (hash.b | (~hash.d))));
			g = (k <= 47 ? ((k << 1) + k + 5) % 16 :
				((k << 3) - k) % 16);
		}
		f = f + hash.a + g_md5_k[k] + m[g];
		hash = md5_hash_cycle(hash, f, k);
		k++;
	}
	return (hash);
}

t_hash		md5_hash_cycle(t_hash hash, uint32_t f, uint32_t k)
{
	hash.a = hash.d;
	hash.d = hash.c;
	hash.c = hash.b;
	hash.b = hash.b + BIT_RL32(f, g_md5_s[k]);
	return (hash);
}

t_hash		base_set(t_hash base, t_hash hash)
{
	base.a = (base.a + hash.a) & 0xFFFFFFFF;
	base.b = (base.b + hash.b) & 0xFFFFFFFF;
	base.c = (base.c + hash.c) & 0xFFFFFFFF;
	base.d = (base.d + hash.d) & 0xFFFFFFFF;
	return (base);
}

uint32_t	*digest_md5(t_hash base)
{
	uint32_t	*digest;

	digest = ft_memalloc(sizeof(uint32_t) * 4);
	ft_memcpy(&digest[0], &base.a, 4);
	ft_memcpy(&digest[1], &base.b, 4);
	ft_memcpy(&digest[2], &base.c, 4);
	ft_memcpy(&digest[3], &base.d, 4);
	return (digest);
}
