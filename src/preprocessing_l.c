/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:36:12 by jochang           #+#    #+#             */
/*   Updated: 2018/08/09 17:03:55 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		set_len(uint64_t *lo, uint64_t *hi, uint64_t count)
{
	*lo += count;
	if (*lo < count)
		*hi += 1;
}

void			pad_input_l(uint8_t **input, uint64_t *len, int32_t rev)
{
	uint8_t				*ptr;

	ptr = *input;
	(void)rev;
	*len <<= 3;
	len[0] = (len[1] >> 61) | (len[0] << 3);
	len[1] = len[1] << 3;
	ft_memcpy(&ptr[112], &len[0], 16);
}

uint64_t		*get_chunk_l(int32_t fd, int32_t rev)
{
	uint64_t			*chunk;
	static uint64_t		len[2];
	static int32_t		toggle;
	int32_t				count;
	uint8_t				*buf;

	if (toggle == 2)
	{
		toggle = 0;
		len[0] = 0;
		len[1] = 0;
		return (NULL);
	}
	buf = (uint8_t*)ft_memalloc(128);
	count = (fd > 0 ? read(fd, buf, 128) : ft_getnstdin(128, (char**)&buf));
	set_len(&len[1], &len[0], count);
	buf[count] = (count < 128 && !toggle ? (uint8_t)0x80 : buf[count]);
	toggle += (count < 128 && !toggle ? 1 : 0);
	(count < 112 ? pad_input_l(&buf, &len[0], rev) : 1);
	toggle += (count < 112 ? 1 : 0);
	chunk = (uint64_t*)ft_memalloc(128);
	ft_memcpy(chunk, buf, 128);
	chunk = ft_swapnendian64(chunk, (toggle == 2 ? 14 : 16));
	free(buf);
	return (chunk);
}

static uint64_t	ft_getstrchunk(uint64_t bits, char *str, char **buf)
{
	int32_t				len;
	static uint64_t		total;

	len = MIN(bits, (uint64_t)ft_strlen(&str[total]));
	ft_memcpy(*buf, &str[total], len);
	total += len;
	if (bits - len >= 8)
		total = 0;
	return (len);
}

uint64_t		*get_str_chunk_l(char *str, int32_t rev)
{
	uint64_t			*chunk;
	static uint64_t		len[2];
	static int32_t		toggle;
	int32_t				count;
	uint8_t				*buf;

	if (toggle == 2)
	{
		toggle = 0;
		len[0] = 0;
		len[1] = 0;
		return (NULL);
	}
	buf = (uint8_t*)ft_memalloc(128);
	count = ft_getstrchunk(128, str, (char**)&buf);
	set_len(&len[1], &len[0], count);
	buf[count] = (count < 128 && !toggle ? (uint8_t)0x80 : buf[count]);
	toggle += (count < 128 && !toggle ? 1 : 0);
	(count < 112 ? pad_input_l(&buf, &len[0], rev) : 1);
	toggle += (count < 112 ? 1 : 0);
	chunk = (uint64_t*)ft_memalloc(128);
	ft_memcpy(chunk, buf, 128);
	chunk = ft_swapnendian64(chunk, (toggle == 2 ? 14 : 16));
	free(buf);
	return (chunk);
}
