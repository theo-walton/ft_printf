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

static char	*reducestr(char *str, int size)
{
	char *new;
	int i;
	int p;
	int q;

	i = 0;
	while (str[i] == '\0' && i < size)
		i++;
	p = i;
	while (str[p] != '\0')
	{
		p++;
	}
	if (!(new = ft_strnew(sizeof(char) * (p - i))))
	{
		free(str);
		return (NULL);
	}
	q = 0;
	while (i < p)
		new[q++] = str[i++];
	free(str);
	return (new);
}

static void	upper_digits(char *digits)
{
	int i;

	i = 8;
	while (++i < 16)
		digits[i] = digits[i] - 32;
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
	char *digits = "0123456789abcdef";
	char *str;
	int i;

	if (num == 0)
		return (zerostring());
	if (xX == 'X')
		upper_digits(digits);
	i = sizeof(uintmax_t);
	if ((str = ft_strnew(sizeof(char) * i)) == NULL)
		return (NULL);
	while (num)
	{
		str[--i] = num % base + '0';
		num = num / base;
	}
	return (reducestr(str, sizeof(uintmax_t)));
}
