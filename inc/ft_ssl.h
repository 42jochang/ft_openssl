/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:40:50 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 20:13:32 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "md5.h"
# include "sha256.h"
# include "sha224.h"
# include "sha512.h"
# include "sha384.h"
# include "dispatch.h"

typedef struct	s_flags
{
	uint32_t	p:1;
	uint32_t	q:1;
	uint32_t	r:1;
	uint32_t	s:1;
	uint32_t	err:1;
}				t_flags;

void			arg_handler(int ac, char **av, t_flags flags);
int32_t			get_hash(char *s);
int32_t			get_hash_size(int32_t hash_type);
void			*hash_selector(int32_t hash_type, char *file_name, char *str);

t_flags			init_flags(void);
t_flags			set_flags(char c, t_flags flags);
t_flags			get_flags(int32_t ac, char **av);
void			p_flag(int32_t toggle, int32_t hash_num);
void			s_flag(int32_t hash_num, char *hash_type, t_flags flags);

void			display_usage(void);
void			display_invoption(char *hash, char invalid);
void			display_invcommand(char *invalid);
void			display_invfile(char *hash, char *file_name);
void			print_memory(uint32_t *digest, size_t size);
void			print_ssl(char *hash_type, t_flags flags,
						char *input, void *output);

void			pad_input(uint8_t **input, uint64_t len, int32_t rev);
uint32_t		*get_chunk(int32_t fd, int32_t rev);
uint32_t		*get_str_chunk(char *str, int32_t rev);

void			pad_input_l(uint8_t **input, uint64_t *len, int32_t rev);
uint64_t		*get_chunk_l(int32_t fd, int32_t rev);
uint64_t		*get_str_chunk_l(char *str, int32_t rev);

int				ft_getnstdin(int32_t n, char **string);
uint64_t		ft_swapendian64(uint64_t i);
uint64_t		*ft_swapnendian64(uint64_t *arr, int32_t n);

#endif
