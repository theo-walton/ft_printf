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

static int	add_charrr(char **str, char c)
{
	char *temp;
	int i;
	int strlen;

	strlen = ft_strlen(*str);
	i = 0;
	if (!(temp = ft_strnew(sizeof(char) * (strlen + 1))))
	{
		free(*str);
		return (0);
	}
	while (i < strlen)
	{
		temp[i + 1] = (*str)[i];
		++i;
	}
	temp[0] = c;
	free(*str);
	*str = temp;
	return (1);
}

static int	add_char(char **str, char c)
{
	if ((*str)[0] == '0')
	{
		(*str)[0] = c;
		return (1);
	}
	else
		return (add_charrr(str, c));
}

static int	add_charr(char **str, char c, t_info *new)
{
	char *temp;
	int i;
	int strlen;

	if (new->toggle)
		return (add_char(str, c));
	strlen = ft_strlen(*str);
	i = 0;
	if (!(temp = ft_strnew(sizeof(char) * (strlen + 1))))
	{
		free(*str);
		return (0);
	}
	while (i < strlen)
	{
		temp[i + 1] = (*str)[i];
		++i;
	}
	temp[0] = c;
	free(*str);
	*str = temp;
	return (1);
}

int	add_sign(char **str, t_info *new)
{
	(new->toggle)++;
	if ((new->flag2 || new->toggle) && !(new->flag2 && new->toggle))
		return (1);
	if (new->flag6)
	{
		if (!add_charr(str, '-', new))
			return (0);
		return (1);
	}
	if (new->flag3)
	{
		if (!add_charr(str, '+', new))
			return (0);
		return (1);
	}
	if (new->flag5)
	{
		if (!add_charr(str, ' ', new))
			return (0);
		return (1);
	}
	return (1);
}
