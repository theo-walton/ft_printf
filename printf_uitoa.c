/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uitoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 18:04:16 by twalton           #+#    #+#             */
/*   Updated: 2017/06/25 18:04:16 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*reducestr(char **str)
{
	char *new;
	int i;
	int p;
	int q;

	i = 0;
	while ((*str)[i] == '\0')
		i++;
	p = i;
	while ((*str)[p] != '\0')
	{
		p++;
	}
	new = ft_strnew(sizeof(char) * (p - i));
	q = 0;
	while (i < p && new)
		new[q++] = (*str)[i++];
	free(*str);
	*str = NULL;
	return (new);
}

static void	get_digits(char *digits, char xX)
{
	int i;

	i = 0;
	while (i < 10)
	{
		digits[i] = i + '0';
		i++;
	}
	if (xX == 'x')
	{
		while (i < 16)
		{
			digits[i] = i + 'a' - 10;
				i++;
		}
	}
	else
	{
		while (i < 16)
		{
			digits[i] = i + 'A' - 10;
			i++;
		}
	}
}

static char	*zerostring(void)
{
	char *new;

	if (!(new = ft_strnew(sizeof(char))))
		return (NULL);
	new[0] = '0';
	return (new);
}

char	*printf_uitoa(uintmax_t num, int base, char xX)
{
	char digits[16];
	char *str;
	int i;

	if (num == 0)
		return (zerostring());
	get_digits(digits, xX);
	i = sizeof(uintmax_t) * 2;
	if ((str = ft_strnew(sizeof(char) * i)) == NULL)
		return (NULL);
	while (num)
	{
		str[--i] = digits[num % base];
		num = num / base;
	}
	return (reducestr(&str));
}
