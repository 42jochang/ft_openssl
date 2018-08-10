/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:04:41 by jochang           #+#    #+#             */
/*   Updated: 2018/07/04 09:17:21 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t		g_sha224_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

t_sha224_hash	sha224_h_init(void)
{
	t_sha224_hash	init;

	init.a = 0xc1059ed8;
	init.b = 0x367cd507;
	init.c = 0x3070dd17;
	init.d = 0xf70e5939;
	init.e = 0xffc00b31;
	init.f = 0x68581511;
	init.g = 0x64f98fa7;
	init.h = 0xbefa4fa4;
	return (init);
}

uint32_t		*sha224_w_init(uint32_t *m)
{
	uint32_t		*w;
	uint32_t		s0;
	uint32_t		s1;
	int32_t			i;

	if (!(w = (uint32_t*)ft_memalloc(sizeof(uint32_t) * 64)))
		return (NULL);
	ft_memcpy(w, m, 64);
	i = 15;
	while (++i < 64)
	{
		s0 = BIT_RR32(w[i - 15], 7) ^ BIT_RR32(w[i - 15], 18) ^
			(w[i - 15] >> 3);
		s1 = BIT_RR32(w[i - 2], 17) ^ BIT_RR32(w[i - 2], 19) ^
			(w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
	}
	return (w);
}
