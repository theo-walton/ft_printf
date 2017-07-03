/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:18:49 by twalton           #+#    #+#             */
/*   Updated: 2017/06/25 22:18:49 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_charr(char **str, char c)
{
	char *new;
	int i;
	int strlen;

	strlen = ft_strlen(*str);
	i = 0;
	if (!(new = ft_strnew(sizeof(char) * (strlen + 1))))
	{
		//free(*str);
		return (0);
	}
	while (i < strlen)
	{
		new[i + 1] = (*str)[i];
		++i;
	}
	new[0] = c;
	//free(*str);
	*str = new;
	return (1);
}

int	add_sign(char **str, t_info *new)
{
	if (new->flag6)
	{
		if (!add_charr(str, '-'))
			return (0);
		return (1);
	}
	if (new->flag3)
	{
		if (!add_charr(str, '+'))
			return (0);
		return (1);
	}
	if (new->flag5)
	{
		if (!add_charr(str, ' '))
			return (0);
		return (1);
	}
	return (1);
}
