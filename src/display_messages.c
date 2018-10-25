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

void	display_invoption(char *hash, char invalid)
{
	ft_putstr(hash);
	ft_putstr(": illegal option -- ");
	ft_putchar(invalid);
	ft_putchar('\n');
	err_usage(1);
}

void	display_invfile(char *hash, char *file_name)
{
	ft_putstr(hash);
	ft_putstr(": ");
	ft_putstr(file_name);
	ft_putstr(": No such file or directory");
	ft_putchar('\n');
}
