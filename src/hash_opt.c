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
	{"md5", 16, &md5},
	{"sha256", 32, &sha256},
	{"sha224", 28, &sha224},
	{"sha512", 64, &sha512},
	{"sha384", 48, &sha384}
};

void		*hash_selector(char *cmd, char *file_name, char *str)
{
	int		i;

	i = -1;
	while (++i < OPT_COUNT)
		if (ft_strequ(g_select[i].cmd, cmd))
			return (g_select[i].s(file_name, str));
	return (NULL);
}

int			get_hash_size(char *cmd)
{
	int		i;

	i = -1;
	while (++i < OPT_COUNT)
		if (ft_strequ(g_select[i].cmd, cmd))
			return (g_select[i].size);
	return (0);
}
