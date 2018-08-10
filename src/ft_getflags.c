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

t_flags		init_flags(void)
{
	t_flags	flags;

	flags.p = 0;
	flags.q = 0;
	flags.r = 0;
	flags.s = 0;
	flags.err = 0;
	return (flags);
}

t_flags		set_flags(char c, t_flags flags)
{
	flags.p = (c == 'p' ? 1 : flags.p);
	flags.q = (c == 'q' ? 1 : flags.q);
	flags.r = (c == 'r' ? 1 : flags.r);
	flags.s = (c == 's' ? 1 : flags.s);
	return (flags);
}

void		p_flag(int toggle, int hash_num)
{
	char		*input;
	uint32_t	*output;

	input = (toggle ? "" : ft_getstdin());
	output = hash_selector(hash_num, NULL, input);
	ft_putstr(input);
	ft_printmemory(output, get_hash_size(hash_num), 0, 0);
	free(output);
	ft_putchar('\n');
}

void		s_flag(int hash_num, char *hash_type, t_flags flags)
{
	uint32_t	*output;

	if (g_optarg)
	{
		output = hash_selector(hash_num, NULL, g_optarg);
		print_ssl(hash_type, flags, g_optarg, output);
	}
	else
	{
		ft_putstr(hash_type);
		ft_putstr(": option requires an argument -- s\n");
		display_usage();
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
		(opt == 'p' ? p_flag(toggle, get_hash(av[1])) : 1);
		toggle = (opt == 'p' ? 1 : 0);
		(opt == 's' ? s_flag(get_hash(av[1]), av[1], flags) : 1);
	}
	return (flags);
}
