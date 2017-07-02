/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:58:57 by twalton           #+#    #+#             */
/*   Updated: 2017/06/20 22:58:57 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_till_control(const char *format, int *i)
{
	int ret;

	ret = 0;
	while (format[*i] != '%' && format[*i])
	{
		ft_putchar(format[*i]);
		++(*i);
		++ret;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int i;
	int total_print;
	int ret;

	i = 0;
	total_print = 1;
	ret = 0;
	va_start(arg, format);
	while (format[i] && total_print)
	{
		total_print = print_till_control(format, &i);
		ret = ret + total_print;
		if (format[i])
			total_print = command_center(arg, what_control(format, &i));
		ret = ret + total_print;
		if (total_print < 0)
			ret = total_print;
	}
	return (ret);
}
