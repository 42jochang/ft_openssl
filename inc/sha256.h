/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:06:31 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 15:42:01 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
# define SHA256_H

extern uint32_t	g_sha256_k[64];

typedef struct	s_sha256_hash
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}				t_sha256_hash;

void			*sha256(char *file_name, char *str);
uint32_t		*sha256_w_init(uint32_t *m);
uint32_t		*digest_sha256(t_sha256_hash base);
t_sha256_hash	sha256_loop(t_sha256_hash hash, uint32_t *w);
t_sha256_hash	sha256_h_init(void);
t_sha256_hash	sha256_hash_cycle(t_sha256_hash hash,
					uint32_t temp1, uint32_t temp2);
t_sha256_hash	sha256_base_set(t_sha256_hash base, t_sha256_hash hash);

#endif
