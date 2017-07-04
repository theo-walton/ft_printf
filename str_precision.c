/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:01:35 by twalton           #+#    #+#             */
/*   Updated: 2017/06/22 22:01:35 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_zeros(char **str, int num)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(sizeof(char) * (ft_strlen(*str) + num));
	if (new == NULL)
	{
		free(*str);
		return (0);
	}
	while (i < num)
		new[i++] = '0';
	while ((*str)[i - num])
	{
		new[i] = (*str)[i - num];
		++i;
	}
	free(*str);
	*str = new;
	return (1);
}

static int	edgecases(char **str)
{
	char *new;

	if ((*str)[0] == '0')
	{
		if (!(new = ft_strnew(0)))
			return (0);
		return (1);
	}
	return (1);
}

int			str_precision(char **str, t_info *new)
{
	int extra;

	if (new->precision < 0)
		return (1);
	if (new->precision == 0)
		return (edgecases(str));
	if (new->specifier == 'd' || new->specifier == 'i' || new->specifier
	== 'o' || new->specifier == 'u' || new->specifier == 'x' ||
	new->specifier == 'X')
	{
		extra = new->precision - (int)ft_strlen(*str);
		if (extra <= 0)
			return (1);
		if (!add_zeros(str, extra))
			return (0);
	}
	else if (new->specifier == 's')
	{
		if (new->precision > (int)ft_strlen(*str))
			return (1);
		(*str)[new->precision] = '\0';
		return (1);
	}
	return (1);
}
