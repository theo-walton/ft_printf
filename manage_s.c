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

int	manage_s(va_list arg, t_info *new)
{
	char *str;
	int strlen;

	if (new->length == 'l')
		return (handle_wide_str(arg, new));
	str = ft_strdup(va_arg(arg, char*));
	if (!str_precision(&str, new))
		return (-1);
	if (!str_width(&str, new))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
