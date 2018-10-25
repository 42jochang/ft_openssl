/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:13:37 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 16:25:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	arg_handler(int ac, char **av, t_flags flags)
{
	uint32_t	*output;

	flags.s = 0;
	while (g_optind < ac)
	{
		if ((output = hash_selector(av[1], av[g_optind], NULL)))
			print_ssl(av[1], flags, av[g_optind], output);
		else
			display_invfile(av[1], av[g_optind]);
		g_optind++;
	}
}

int		main(int ac, char **av)
{
	uint32_t	*output;
	t_flags		flags;

	err_usage(ac);
	err_invcommand(av[1]);
	flags = get_flags(ac, av);
	ERROR_CHECK(flags.err);
	if (g_optind >= ac && !flags.p && !flags.s)
	{
		output = hash_selector(av[1], NULL, NULL);
		ft_printmemory(output, get_hash_size(av[1]), 0, 0);
		free(output);
		ft_putchar('\n');
	}
	arg_handler(ac, av, flags);
	return (0);
}
