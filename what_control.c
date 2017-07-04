/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 01:28:54 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 01:28:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*what_control(const char *format, int *i)
{
	t_info *new;

	(*i)++;
	if (format[*i] == '%')
	{
		ft_putchar('%');
		++(*i);
		return ((t_info*)1);
	}
	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->flag1 = 0;
	new->flag2 = 0;
	new->flag3 = 0;
	new->flag4 = 0;
	new->flag5 = 0;
	new->flag6 = 0;
	new->toggle = -1;
	check_flag(format, i, new);
	check_width(format, i, new);
	check_precision(format, i, new);
	check_length(format, i, new);
	check_specifier(format, i, new);
	return (new);
}
