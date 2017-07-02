/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:09:21 by twalton           #+#    #+#             */
/*   Updated: 2017/06/24 23:09:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_unsigned_arg(va_list arg, t_info *new)
{
	uintmax_t ret;

	ret = 12345678;
	if (new->length == 'l')
		ret = va_arg(arg, unsigned long int);
	if (new->length == 'b')
		ret = va_arg(arg, unsigned long long int);
	if (new->length == 'h')
		ret = (unsigned short int)va_arg(arg, unsigned int);
	if (new->length == 'a')
		ret = (unsigned char)va_arg(arg, unsigned int);
	if (new->length == 'j')
		ret = va_arg(arg, uintmax_t);
	if (new->length == 'z')
		ret = va_arg(arg, size_t);
	return (ret);
}
