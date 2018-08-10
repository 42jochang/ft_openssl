/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:46:17 by jochang           #+#    #+#             */
/*   Updated: 2018/08/08 16:06:20 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

# define OPT_COUNT 5

typedef void	*(*t_fun) (char *, char *);

typedef struct	s_dispatch
{
	int			op;
	t_fun		s;
}				t_dispatch;

extern const t_dispatch	g_select[];

#endif
