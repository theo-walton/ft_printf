/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:32:13 by twalton           #+#    #+#             */
/*   Updated: 2017/06/22 18:32:13 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*printf_strdup(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

int			manage_s(va_list *arg, t_info *new)
{
	char	*str;
	int		strlen;

	if (new->length == 'l')
	{
		return (handle_wide_str(arg, new));
	}
	if (!(str = printf_strdup(va_arg(*arg, char*))))
		return (-1);
	if (!str_precision(&str, new))
		return (-1);
	if (!str_width(&str, new))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
