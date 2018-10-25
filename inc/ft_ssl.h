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
# include "../libft/inc/libft.h"
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
int32_t			get_hash_size(char *cmd);
void			*hash_selector(char *cmd, char *file_name, char *str);

t_flags			get_flags(int32_t ac, char **av);

void			err_usage(int ac);
void			err_invcommand(char *cmd);

void			display_invoption(char *hash, char invalid);
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
