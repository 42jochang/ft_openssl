/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:42:44 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 15:40:46 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

extern uint32_t	g_md5_k[64];
extern uint32_t	g_md5_s[64];

typedef struct	s_hash
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
}				t_hash;

void			*md5(char *file_name, char *str);
uint32_t		*digest_md5(t_hash base);
t_hash			md5_loop(t_hash hash, uint32_t *m);
t_hash			md5_hash_cycle(t_hash hash, uint32_t f, uint32_t k);
t_hash			base_set(t_hash base, t_hash hash);
t_hash			h_init(void);

#endif
