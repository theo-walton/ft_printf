/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:14:04 by twalton           #+#    #+#             */
/*   Updated: 2017/06/24 23:14:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_0x(char **str)
{
	int		strlen;
	char	*new;

	strlen = ft_strlen(*str);
	if (!(new = ft_strnew(sizeof(char) * strlen + 2)))
	{
		free(*str);
		return (0);
	}
	if (!ft_memmove(new + 2, *str, strlen + 1))
	{
		free(*str);
		return (0);
	}
	new[0] = '0';
	new[1] = 'x';
	free(*str);
	*str = new;
	return (1);
}

int			manage_x(va_list *arg, t_info *new)
{
	uintmax_t	num;
	char		*str;
	int			strlen;

	if (new->length != '\0')
		num = get_unsigned_arg(arg, new);
	else
		num = va_arg(*arg, unsigned int);
	str = printf_uitoa(num, 16, 'x');
	if (str == NULL)
		return (-1);
	if (!str_precision(&str, new))
		return (-1);
	if (new->flag1)
		if (!add_0x(&str))
			return (-1);
	if (!str_width(&str, new))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
