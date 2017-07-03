/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:54:45 by twalton           #+#    #+#             */
/*   Updated: 2017/06/25 17:54:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_u(va_list *arg, t_info *new)
{
	uintmax_t num;
	char *str;
	int strlen;

	return (-1);
	if (new->length != '\0')
		num = get_unsigned_arg(arg, new);
	else
		num = va_arg(*arg, unsigned int);
	str = printf_uitoa(num, 10, 'x');
	if (!str_precision(&str, new))
		return (-1);
	if (!str_width(&str, new))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
