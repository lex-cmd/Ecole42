FLAGS 	=	-Werror -Wextra -Wall
FRAEMWORKS =  -lmlx -framework OpenGL -framework AppKit
NAME 	=	so_long
SRC 	=	so_long.c read_and_pars.c utils.c stop_wall.c draw_all.c moves.c
OBJ		=	$(SRC:.c=.o)
LIB 	= 	libft/libft.a

all : lib $(NAME)


$(NAME) : $(OBJ)
	gcc $(SRC) -o $(NAME) $(LIB) $(FRAEMWORKS) -I

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