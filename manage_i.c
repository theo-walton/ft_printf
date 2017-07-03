/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 17:40:36 by twalton           #+#    #+#             */
/*   Updated: 2017/06/25 17:40:36 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	make_pos(intmax_t num)
{
	uintmax_t ret;

	ret = -num;
	return (ret);
}

static void	check_negative(intmax_t num, uintmax_t *num2, t_info *new)
{
	if (num < 0)
	{
		new->flag6 = 1;
		*num2 = make_pos(num);
	}
	else
		*num2 = num;
}

int	manage_i(va_list *arg, t_info *new)
{
	intmax_t num;
	uintmax_t num2;
	char *str;
	int strlen;

	if (new->length != '\0')
		num = get_signed_arg(arg, new);
	else
		num = va_arg(*arg, int);
	check_negative(num, &num2, new);
	if (!(str = printf_uitoa(num2, 10, 'x')))
		return (-1);
	if (!str_precision(&str, new))
		return (-1);
	if (!(add_sign(&str, new)))
		return (-1);
	if (!str_width(&str, new))
		return (-1);
	if (!(add_sign(&str, new)))
		return (-1);
	ft_putstr(str);
	strlen = ft_strlen(str);
	free(str);
	return (strlen);
}
