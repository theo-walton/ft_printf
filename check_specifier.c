/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:52:01 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 18:52:01 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_specifier4(const char *format, int *i, t_info *new)
{
	if (format[*i] == 'c')
	{
                new->specifier = 'c';
                ++(*i);
        }
	else if	(format[*i] == 'C')
	{
                new->specifier = 'C';
                ++(*i);
        }
	else
		new->specifier = '\0';
}

static void	check_specifier3(const char *format, int *i, t_info *new)
{
	if (format[*i] == 'u')
	{
                new->specifier = 'u';
                ++(*i);
        }
	else if	(format[*i] == 'U')
	{
                new->specifier = 'U';
                ++(*i);
        }
	else if	(format[*i] == 'x')
	{
                new->specifier = 'x';
                ++(*i);
        }
	else if	(format[*i] == 'X')
	{
                new->specifier = 'X';
                ++(*i);
        }
	else 
		check_specifier4(format, i, new);
}

static void	check_specifier2(const char *format, int *i, t_info *new)
{
	if (format[*i] == 'D')
	{
                new->specifier = 'D';
                ++(*i);
        }
	else if	(format[*i] == 'i')
	{
                new->specifier = 'i';
                ++(*i);
        }
	else if	(format[*i] == 'o')
	{
                new->specifier = 'o';
                ++(*i);
        }
	else if	(format[*i] == 'O')
	{
                new->specifier = 'O';
                ++(*i);
        }
	else 
		check_specifier3(format, i, new);
}

void	check_specifier(const char *format, int *i, t_info *new)
{
	if (format[*i] == 's')
	{
		new->specifier = 's';
		++(*i);
	}
	else if (format[*i] == 'S')
	{
		new->specifier = 'S';
		++(*i);
	}
	else if	(format[*i] == 'p')
	{
                new->specifier = 'p';
                ++(*i);
        }
	else if	(format[*i] == 'd')
	{
                new->specifier = 'd';
                ++(*i);
        }
	else 
		check_specifier2(format, i, new);
}
