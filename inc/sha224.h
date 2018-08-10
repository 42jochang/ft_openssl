/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:06:31 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 15:42:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA224_H
# define SHA224_H

extern uint32_t		g_sha224_k[64];

typedef struct		s_sha224_hash
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
}					t_sha224_hash;

void				*sha224(char *file_name, char *str);
uint32_t			*sha224_w_init(uint32_t *m);
uint32_t			*digest_sha224(t_sha224_hash base);
t_sha224_hash		sha224_loop(t_sha224_hash hash, uint32_t *w);
t_sha224_hash		sha224_h_init(void);
t_sha224_hash		sha224_hash_cycle(t_sha224_hash hash,
					uint32_t temp1, uint32_t temp2);
t_sha224_hash		sha224_base_set(t_sha224_hash base, t_sha224_hash hash);

#endif
