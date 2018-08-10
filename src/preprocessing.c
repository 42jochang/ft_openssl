/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:36:12 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 15:15:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		pad_input(uint8_t **input, uint64_t len, int32_t rev)
{
	uint8_t				*ptr;

	ptr = *input;
	len <<= 3;
	if (rev)
		len = ft_swapendian64(len);
	ft_memcpy(&ptr[56], &len, 8);
}

uint32_t	*get_chunk(int32_t fd, int32_t rev)
{
	uint32_t			*chunk;
	static uint64_t		len;
	static int32_t		toggle;
	int32_t				count;
	uint8_t				*buf;

	if (toggle == 2)
	{
		toggle = 0;
		len = 0;
		return (NULL);
	}
	buf = (uint8_t*)ft_memalloc(64);
	count = (fd > 0 ? read(fd, buf, 64) : ft_getnstdin(64, (char**)&buf));
	len += count;
	buf[count] = (count < 64 && !toggle ? (uint8_t)0x80 : buf[count]);
	toggle += (count < 64 && !toggle ? 1 : 0);
	(count < 56 ? pad_input(&buf, len, rev) : 1);
	toggle += (count < 56 ? 1 : 0);
	chunk = (uint32_t*)ft_memalloc(64);
	ft_memcpy(chunk, buf, 64);
	chunk = (rev ? ft_swapnendian(chunk, 16) : chunk);
	free(buf);
	return (chunk);
}

uint32_t	*get_str_chunk(char *str, int32_t rev)
{
	uint32_t			*chunk;
	static int32_t		toggle;
	static int32_t		i;
	uint8_t				*buf;
	int32_t				len;

	if (toggle == 2)
	{
		i = 0;
		toggle = 0;
		return (NULL);
	}
	buf = (uint8_t*)ft_memalloc(64);
	len = ft_strlen(&str[i]);
	ft_memcpy(buf, &str[i], (len >= 64 ? 64 : len));
	buf[len] = (len < 64 && !toggle ? (uint8_t)0x80 : buf[len]);
	toggle += (len < 64 && !toggle ? 1 : 0);
	(len < 56 ? pad_input(&buf, ft_strlen(str), rev) : 1);
	toggle += (len < 56 ? 1 : 0);
	chunk = (uint32_t*)ft_memalloc(64);
	ft_memcpy(chunk, buf, 64);
	chunk = (rev ? ft_swapnendian(chunk, 16) : chunk);
	free(buf);
	i += (len > 64 ? 64 : len);
	return (chunk);
}
