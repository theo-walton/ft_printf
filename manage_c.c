/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 22:47:22 by twalton           #+#    #+#             */
/*   Updated: 2017/06/26 22:47:22 by twalton          ###   ########.fr       */
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

int			manage_c(va_list *arg, t_info *new)
{
	char c;

	if (new->length == 'l')
		return (handle_wide_char(arg, new));
	c = (char)va_arg(*arg, int);
	if (new->flag4)
	{
		ft_putchar(c);
		width(new);
	}
	else
	{
		width(new);
		ft_putchar(c);
	}
	if (new->width)
		return (new->width);
	return (1);
}
