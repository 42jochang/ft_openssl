/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:15:25 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 17:04:14 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getstdin(void)
{
	int		ret;
	char	*buf;
	char	*str;
	char	*tmp;

	str = (char*)ft_memalloc(1);
	buf = (char*)ft_memalloc(65);
	while ((ret = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	free(buf);
	return (str);
}
