/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:06:31 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 15:43:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

extern uint64_t	g_sha512_k[80];

typedef struct	s_sha512_hash
{
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
}				t_sha512_hash;

void			*sha512(char *file_name, char *str);
uint64_t		*sha512_w_init(uint64_t *m);
uint64_t		*digest_sha512(t_sha512_hash base);
t_sha512_hash	sha512_loop(t_sha512_hash hash, uint64_t *w);
t_sha512_hash	sha512_h_init(void);
t_sha512_hash	sha512_hash_cycle(t_sha512_hash hash,
					uint64_t temp1, uint64_t temp2);
t_sha512_hash	sha512_base_set(t_sha512_hash base, t_sha512_hash hash);

#endif
