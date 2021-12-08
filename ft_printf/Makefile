# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 13:29:55 by fcarl             #+#    #+#              #
#    Updated: 2021/05/23 13:09:14 by fcarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =		ft_putstr.c			ft_putnbr.c		ft_putchar.c \
			gen_parsing.c		ft_printf.c		ft_isdigit.c \
			nbrlens.c			ft_atoi.c		ft_print_char.c \
			ft_print_str.c		ft_strlen.c		printf_fill_flags.c\
			ft_print_digit.c	\
			ft_printf_utils.c		\
			ft_putchar_fd.c		\
			print_percent.c		\
			ft_printf.h

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror


$(NAME): all


all: 	$(OBJ)
		ar rcs $(NAME) $?

%.o: %.c ft_printf.h
			gcc $(FLAGS) -c $< -o $@

norme	:
	norminette $(SRC)

c		:
	make
	gcc -g libftprintf.a
	./a.out

clean	:
	rm -rf *.o

fclean	: clean
	rm -rf $(NAME) *.o *.out

re	: fclean all

.PHONY	: all clean fclean re bonus