/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ssl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:21:38 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 22:46:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_ssl(char *hash_type, t_flags flags, char *input,
				void *output)
{
	char	*ht;

	ht = ft_strupper(hash_type);
	if (input && !flags.r && !flags.q)
	{
		ft_putstr(ht);
		ft_putstr(" (");
		(flags.s ? ft_putstr("\"") : 1);
		ft_putstr(input);
		(flags.s ? ft_putstr("\"") : 1);
		ft_putstr(") = ");
	}
	ft_printmemory(output, get_hash_size(get_hash(hash_type)), 0, 0);
	if (input && flags.r && !flags.q)
	{
		ft_putchar(' ');
		(flags.s ? ft_putstr("\"") : 1);
		ft_putstr(input);
		(flags.s ? ft_putstr("\"") : 1);
	}
	ft_putchar('\n');
	free(output);
	free(ht);
}
