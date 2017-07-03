/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wide_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 09:58:09 by twalton           #+#    #+#             */
/*   Updated: 2017/06/27 09:58:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width(t_info *new)
{
	int width;

	width = new->width;
	while (width > 1)
	{
		if (new->flag2)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
}

int	handle_wide_char(va_list *arg, t_info *new)
{
	int i;

	i = va_arg(*arg, int);
	if (new->flag4)
	{
		print_wide_char(i);
		width(new);
	}
	else
	{
		width(new);
		print_wide_char(i);
	}
	if (new->width)
		return (new->width);
	return (1);
}
