/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:16:45 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 18:16:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(const char *format, int *i, t_info *new)
{
	int num;

	num = 0;
	while (ft_isdigit(format[*i]))
	{
		num = 10 * num + (int)format[*i] - '0';
		++(*i);
	}
	new->width = num;
}
