/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:31:37 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 16:17:52 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_flags		init_flags(void)
{
	t_flags	flags;

	flags.p = 0;
	flags.q = 0;
	flags.r = 0;
	flags.s = 0;
	flags.err = 0;
	return (flags);
}

static t_flags		set_flags(char c, t_flags flags)
{
	flags.p = (c == 'p' ? 1 : flags.p);
	flags.q = (c == 'q' ? 1 : flags.q);
	flags.r = (c == 'r' ? 1 : flags.r);
	flags.s = (c == 's' ? 1 : flags.s);
	return (flags);
}

static void		p_flag(int toggle, char *cmd)
{
	char		*input;
	uint32_t	*output;

	input = (toggle ? "" : ft_getstdin());
	output = hash_selector(cmd, NULL, input);
	ft_putstr(input);
	ft_printmemory(output, get_hash_size(cmd), 0, 0);
	free(output);
	ft_putchar('\n');
}

static void		s_flag(char *cmd, t_flags flags)
{
	uint32_t	*output;

	if (g_optarg)
	{
		output = hash_selector(cmd, NULL, g_optarg);
		print_ssl(cmd, flags, g_optarg, output);
	}
	else
	{
		ft_putstr(cmd);
		ft_putstr(": option requires an argument -- s\n");
		err_usage(1);
	}
}

t_flags		get_flags(int ac, char **av)
{
	t_flags		flags;
	int			opt;
	int			toggle;

	toggle = 0;
	g_optind = 2;
	flags = init_flags();
	while ((opt = ft_getopt(ac, av, "pqrs:")) != -1)
	{
		if (opt == '?')
		{
			display_invoption(av[1], g_optopt);
			flags.err = 1;
			return (flags);
		}
		flags = set_flags(opt, flags);
		(opt == 'p' ? p_flag(toggle, av[1]) : 1);
		toggle = (opt == 'p' ? 1 : 0);
		(opt == 's' ? s_flag(av[1], flags) : 1);
	}
	return (flags);
}
