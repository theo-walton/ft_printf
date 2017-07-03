/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 22:47:40 by twalton           #+#    #+#             */
/*   Updated: 2017/06/24 22:47:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_signed_arg(va_list *arg, t_info *new)
{
	intmax_t ret;

	ret = 12345;
	if (new->length == 'l')
		ret = va_arg(*arg, long int);
	if (new->length == 'b')
		ret = va_arg(*arg, long long int);
	if (new->length == 'h')
		ret = (short int)va_arg(*arg, int);
	if (new->length == 'a')
		ret = (char)va_arg(*arg, int);
	if (new->length == 'j')
		ret = va_arg(*arg, intmax_t);
	if (new->length == 'z')
		ret = va_arg(*arg, size_t);
	return (ret);
}
