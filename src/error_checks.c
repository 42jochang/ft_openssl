/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:57:29 by jochang           #+#    #+#             */
/*   Updated: 2018/10/23 22:00:31 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	err_usage(int ac)
{
    if (ac > 1)
        return ;
    ft_putstr("usage: ./ft_ssl command [-pqr] [-s string] [files...]\n");
    exit(0);
}

void    err_invcommand(char *cmd)
{
    int     i;

    i = -1;
    while (++i < OPT_COUNT)
        if (ft_strequ(g_select[i].cmd, cmd))
            return ;
    ft_putstr("ft_ssl: Error: '");
	ft_putstr(cmd);
	ft_putstr("' is an invalid command.\n\n");
	ft_putstr("Standard commands:\n\n");
	ft_putstr("Message Digest commands:\n");
	ft_putstr("md5\nsha256\nsha224\nsha512\nsha384\n\n");
	ft_putstr("Cipher commands:\n");
    exit(0);
}