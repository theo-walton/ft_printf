/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:57:03 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 17:57:03 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isflag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	return (0);
}

void	check_flag(const char *format, int *i, t_info *new)
{
	int counter;
	int iter;

	iter = 0;
	counter = 0;
	while (isflag(format[*i + counter]) && counter < 5)
		counter++;
	while (*i < counter)
	{
		if (format[*i + iter] == '#')
			new->flag1 = 1;
		if (format[*i +	iter] == '0')
			new->flag2 = 1;
		if (format[*i +	iter] == '+')
			new->flag3 = 1;
		if (format[*i +	iter] == '-')
			new->flag4 = 1;
		if (format[*i +	iter] == ' ')
                        new->flag5 = 1;
		++iter;
	}
	(*i) = (*i) + counter;
}
