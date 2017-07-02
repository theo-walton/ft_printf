/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 01:38:24 by twalton           #+#    #+#             */
/*   Updated: 2017/06/30 01:38:35 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_bit(unsigned char byte, int bit_num)
{
	if (bit_num == 8)
		if ((byte & 1) == byte)
			return (1);
	if (bit_num == 7)
		if ((byte & 2) == byte)
			return (1);
	if (bit_num == 6)
		if ((byte & 4) == byte)
			return (1);
	if (bit_num == 5)
		if ((byte & 8) == byte)
			return (1);
	if (bit_num == 4)
		if ((byte & 16) == byte)
			return (1);
	if (bit_num == 3)
		if ((byte & 32) == byte)
			return (1);
	if (bit_num == 2)
		if ((byte & 64) == byte)
			return (1);
	if (bit_num == 1)
		if ((byte & 128) == byte)
			return (1);
	return (0);
}

void	print_wide_char(int i)
{
	unsigned char *quadbyte;

	quadbyte = (unsigned char*)&i;
	if (!is_bit(quadbyte[0], 1))
		write(1, quadbyte, 1);
	if (is_bit(quadbyte[0], 1) && is_bit(quadbyte[0], 2) && !is_bit(quadbyte[0], 3))
		write(1, quadbyte, 2);
	if (is_bit(quadbyte[0], 1) && is_bit(quadbyte[0], 2) && is_bit(quadbyte[0], 3)
		&& !is_bit(quadbyte[0], 4))
	{
		write(1, quadbyte, 3);
	}
	if (is_bit(quadbyte[0], 1) && is_bit(quadbyte[0], 2) && is_bit(quadbyte[0], 3)
		&& is_bit(quadbyte[0], 4) && !is_bit(quadbyte[0], 5))
	{
		write(1, quadbyte, 4);
	}
}
