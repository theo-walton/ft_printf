# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 16:45:00 by twalton           #+#    #+#              #
#    Updated: 2017/06/30 01:41:13 by twalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	@cp libft/includes/libft.h .
	@gcc -Wall -Wextra -Werror -c *.c libft/*.c -I .
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@rm libft.h

clean:
	@rm -rf $(wildcard *.o)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
