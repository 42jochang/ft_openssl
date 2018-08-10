/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:13:14 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 16:10:55 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const t_dispatch	g_select[] = {
	{1, &md5},
	{2, &sha256},
	{3, &sha224},
	{4, &sha512},
	{5, &sha384}
};

int			get_hash(char *s)
{
	if (ft_strequ(s, "md5"))
		return (1);
	if (ft_strequ(s, "sha256"))
		return (2);
	if (ft_strequ(s, "sha224"))
		return (3);
	if (ft_strequ(s, "sha512"))
		return (4);
	if (ft_strequ(s, "sha384"))
		return (5);
	return (-1);
}

void		*hash_selector(int hash_type, char *file_name, char *str)
{
	int		i;

	i = -1;
	while (++i < OPT_COUNT)
		if (g_select[i].op == hash_type)
			return (g_select[i].s(file_name, str));
	return (NULL);
}

int			get_hash_size(int hash_type)
{
	if (hash_type == 1)
		return (16);
	if (hash_type == 2)
		return (32);
	if (hash_type == 3)
		return (28);
	if (hash_type == 4)
		return (64);
	if (hash_type == 5)
		return (48);
	return (0);
}
