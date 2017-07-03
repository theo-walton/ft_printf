/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:51:00 by twalton           #+#    #+#             */
/*   Updated: 2017/06/25 17:51:00 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_precision(char *str, t_info *new)
{
	int strlen;

	strlen = ft_strlen(str);
	if (new->precision > strlen)
		return ;
	if (str[0] != 0)
	{
		new->precision = strlen + 1;
	}
	else 
		new->precision = 1;
}

int	manage_o(va_list *arg, t_info *new)
{
	uintmax_t num;
	char *str;
	int strlen;

	return (-1);
	if (new->length != '\0')
		num = get_unsigned_arg(arg, new);
	else
		num = va_arg(*arg, unsigned int);
	str = printf_uitoa(num, 8, 'x');
	if (str == NULL)
		return (-1);
	if (new->flag1)
		change_precision(str, new);
	if (!str_precision(&str, new))
		return (-1);
	if (!str_width(&str, new))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
