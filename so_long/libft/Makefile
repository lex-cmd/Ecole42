# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarl <fcarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 09:50:40 by fcarl             #+#    #+#              #
#    Updated: 2021/07/28 20:46:21 by fcarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =		ft_strjoin.c	ft_strlcpy.c	ft_atoi.c\
			ft_strlcat.c	ft_strlen.c		ft_memmove.c\
			ft_isalpha.c	ft_isascii.c	ft_substr.c\
			ft_memcpy.c		ft_bzero.c		ft_strmapi.c\
			ft_memchr.c		ft_memcmp.c		ft_isdigit.c\
			ft_isalnum.c	ft_toupper.c	ft_isprint.c\
			ft_tolower.c	ft_strchr.c		ft_strrchr.c\
			ft_strncmp.c	ft_strnstr.c	ft_calloc.c\
			ft_strdup.c		ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c\
			ft_memset.c		ft_strtrim.c	ft_split.c\
			ft_memccpy.c	ft_lstnew.c\
			ft_lstadd_front.c	ft_lstmap.c\
			ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
			get_next_line.c	ft_newline.c	ft_strcpy.c\
			ft_numstr.c

NAME	=	libft.a
OBJ_D	=	obj/
OBJ		=	$(addprefix $(OBJ_D), $(SRC:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) libft.h
	ranlib $(NAME)

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	mkdir $(OBJ_D)

$(OBJ_D)%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_D)

re: fclean all

.PHONY: all clean fclean re
