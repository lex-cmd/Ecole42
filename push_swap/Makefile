FLAGS = -Werror -Wextra -Wall
NAME = push_swap
SRC = *.c
LIB = libft/libft.a

all : lib 
	gcc $(SRC) -o $(NAME) $(LIB) -I.

lib:
	@make -C libft/ all

clean:
	@make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

c :
	./push_swap 1 2 3

p:
	git add .
	git status
	git commit -m fdf
	git push origin main
