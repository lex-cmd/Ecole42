FLAGS 	=	-Werror -Wextra -Wall
NAME 	=	pipex
SRC 	=	pipex.c	pipex_utils.c
OBJ		=	$(SRC:.c=.o)
LIB 	= 	libft/libft.a

all : lib $(NAME)


$(NAME) : $(OBJ)
	gcc $(SRC) -o $(NAME) $(LIB) -I

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

lib :
	@make -C libft/ all

clean:
	@make -C libft/ clean
	rm -rf *.o

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

p:
	git add .
	git status
	git commit -m pipe
	git push origin main