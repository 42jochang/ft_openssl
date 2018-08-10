/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:47:03 by jochang           #+#    #+#             */
/*   Updated: 2018/07/25 04:01:38 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	display_usage(void)
{
	ft_putstr("usage: ./ft_ssl command [-pqr] [-s string] [files...]\n");
}

void	display_invoption(char *hash, char invalid)
{
	ft_putstr(hash);
	ft_putstr(": illegal option -- ");
	ft_putchar(invalid);
	ft_putchar('\n');
	display_usage();
}

void	display_invcommand(char *invalid)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(invalid);
	ft_putstr("' is an invalid command.\n\n");
	ft_putstr("Standard commands:\n\n");
	ft_putstr("Message Digest commands:\n");
	ft_putstr("md5\nsha256\nsha224\nsha512\nsha384\n\n");
	ft_putstr("Cipher commands:\n");
}

void	display_invfile(char *hash, char *file_name)
{
	ft_putstr(hash);
	ft_putstr(": ");
	ft_putstr(file_name);
	ft_putstr(": No such file or directory");
	ft_putchar('\n');
}
