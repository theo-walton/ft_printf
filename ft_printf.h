/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:21:24 by twalton           #+#    #+#             */
/*   Updated: 2017/06/21 17:21:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_h
# define ft_printf_h

#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct s_info
{
	int flag1;
	int flag2;
	int flag3;
	int flag4;
	int flag5;
	int flag6;
	int toggle;
	int width;
	int precision;
	char length;
	char specifier;
}	t_info;

int	add_sign(char **str, t_info *new);

void	check_flag(const char *format, int *i, t_info *new);
void	check_length(const char *format, int *i, t_info *new);
void	check_precision(const char *format, int *i, t_info *new);
void	check_specifier(const char *format, int *i, t_info *new);
void	check_width(const char *format, int *i, t_info *new);

int	command_center(va_list *arg, t_info *new);
int	ft_printf(const char *format, ...);
intmax_t	get_signed_arg(va_list *arg, t_info *new);
uintmax_t	get_unsigned_arg(va_list *arg, t_info *new);
int	handle_wide_char(va_list *arg, t_info *new);
int	handle_wide_str(va_list *arg, t_info *new);
void    print_wide_char(int i);

int	manage_C(va_list *arg, t_info *new);
int	manage_D(va_list *arg, t_info *new);
int	manage_O(va_list *arg, t_info *new);
int	manage_S(va_list *arg, t_info *new);
int	manage_U(va_list *arg, t_info *new);
int	manage_X(va_list *arg, t_info *new);
int	manage_c(va_list *arg, t_info *new);
int	manage_d(va_list *arg, t_info *new);
int	manage_i(va_list *arg, t_info *new);
int	manage_o(va_list *arg, t_info *new);
int	manage_p(va_list *arg, t_info *new);
int	manage_s(va_list *arg, t_info *new);
int	manage_u(va_list *arg, t_info *new);
int	manage_x(va_list *arg, t_info *new);

char	*printf_uitoa(uintmax_t num, int base, char xX);
int	str_precision(char **str, t_info *new);
int	str_width(char **str, t_info *new);
t_info	*what_control(const char *format, int *i);

#endif
