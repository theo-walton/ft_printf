/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wide_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 13:17:58 by twalton           #+#    #+#             */
/*   Updated: 2017/06/27 13:17:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_wide_len(int *i)
{
	int ret;

	ret = 0;
	while ((char)*i)
	{
		i = i + 4;
		ret++;
	}
	return (ret);
}

static void	print_width(int strlen, t_info *new)
{
	int n;
	int width;

	width = new->width;
	if (new->precision)
	{
		if (strlen > new->precision)
			n = new->precision;
		else
			n = strlen;
	}
	else 
		n = strlen;
	while (width-- > n)
	{
		if (new->flag2)
			ft_putchar('0');
		else 
			ft_putchar(' ');
	}
}

static void	print_wide_str(int *arr, int precision)
{
	int i;

	i = 0;
	if (precision < 0)
		precision = 2147483647;
	while (arr[i] && i < precision)
		print_wide_char(arr[i++]);
}

static int	things_printed(int strlen, t_info *new)
{
	int ret;

	if (strlen > new->precision)
		ret = new->precision;
	else
		ret = strlen;
	if (new->width > ret)
		ret = new->width;
	return (ret);
}

int	handle_wide_str(va_list *arg, t_info *new)
{
	int *arr;
	int strlen;

	arr = va_arg(*arg, int*);
	strlen = get_wide_len(arr);
	if (new->flag4)
	{
		print_wide_str(arr, new->precision);
		print_width(strlen, new);
	}
	else
	{
		print_width(strlen, new);
		print_wide_str(arr, new->precision);
	}
	return (things_printed(strlen, new));
}
