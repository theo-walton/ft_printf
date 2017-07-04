/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:45:55 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 18:45:55 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_length2(const char *format, int *i, t_info *new)
{
	if (format[*i] == 'j')
	{
		new->length = 'j';
		++(*i);
	}
	else if (format[*i] == 'z')
	{
		new->length = 'z';
		++(*i);
	}
	else
		new->length = '\0';
}

void		check_length(const char *format, int *i, t_info *new)
{
	if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
		{
			new->length = 'a';
			++(*i);
		}
		else
			new->length = 'h';
		++(*i);
	}
	else if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
		{
			new->length = 'b';
			++(*i);
		}
		else
			new->length = 'l';
		++(*i);
	}
	else
		check_length2(format, i, new);
}
