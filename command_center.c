/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 20:02:39 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 20:02:39 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	command_center2(va_list arg, t_info *new)
{
	int ret;

	ret = 0;
	if (new->specifier == 'U')
                ret = manage_U(arg, new);
        else if (new->specifier == 'x')
                ret = manage_x(arg, new);
        else if (new->specifier == 'X')
                ret = manage_X(arg, new);
	else if (new->specifier == 'c')
                ret = manage_c(arg, new);
        else if (new->specifier == 'C')
                ret = manage_C(arg, new);
	else if (new->specifier == 'u')
                ret = manage_u(arg, new);
	else if (new->specifier == 'd')
		ret = manage_d(arg, new);
	return (ret);
}

int	command_center(va_list arg, t_info *new)
{
	int ret;

	ret = 0;
	if (new == (t_info*)1)
		return (1);
	else if (new == NULL)
		return (-1);
	else if (new->specifier == 's')
		ret = manage_s(arg, new);
	else if (new->specifier == 'S')
		ret = manage_S(arg, new);
	else if (new->specifier == 'p')
		ret = manage_p(arg, new);
	else if (new->specifier == 'D')
		ret = manage_D(arg, new);
	else if (new->specifier == 'i')
		ret = manage_i(arg, new);
	else if (new->specifier == 'o')
                ret = manage_o(arg, new);
        else if (new->specifier == 'O')
                ret = manage_O(arg, new);
	else 
		ret = command_center2(arg, new);
	free(new);
	return (ret);
}
