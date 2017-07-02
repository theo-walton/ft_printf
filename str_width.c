/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 01:40:35 by twalton           #+#    #+#             */
/*   Updated: 2017/06/23 01:40:35 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_zeros(char **str, int num)
{
	char *new;
	int i;

	i = 0;
	new = ft_strnew(sizeof(char) * (ft_strlen(*str) + num));
	if (new == NULL)
	{
		free(*str);
		return (0);
	}
	while (i < num)
		new[i++] = '0';
	while (*str[i - num])
	{
		new[i] = *str[i - num];
		++i;
	}
	free(*str);
	*str = new;
	return (1);
}

static int      add_blanks_left(char **str, int num)
{
        char *new;
        int i;

        i = 0;
        new = ft_strnew(sizeof(char) * (ft_strlen(*str) + num));
        if (new == NULL)
        {
                free(*str);
                return (0);
        }
        while (i < num)
                new[i++] = ' ';
        while (*str[i - num])
        {
                new[i] = *str[i - num];
                ++i;
        }
        free(*str);
        *str = new;
        return (1);
}

static int      add_blanks_right(char **str, int num)
{
        char *new;
        int i;
	int strlen;

	strlen = ft_strlen(*str);
        i = -1;
        new = ft_strnew(sizeof(char) * (strlen + num));
        if (new == NULL)
        {
                free(*str);
                return (0);
        }
        while (++i < strlen)
		new[i] = *str[i];
	while (++i < strlen + num)
		new[i] = ' ';
        free(*str);
        *str = new;
        return (1);
}

int	str_width(char **str, t_info *new)
{
	if ((int)ft_strlen(*str) >= new->width)
		return (1);
	if (!new->flag3 && new->flag2)
	{
		if (!add_zeros(str, ft_strlen(*str) - new->width))
			return (0);
	}
	if (new->flag3)
	{
		if (!add_blanks_left(str, ft_strlen(*str) - new->width))
			return (0);
		return (1);
	}
	if (!add_blanks_right(str, ft_strlen(*str)))
		return (0);
	return (1);
}
