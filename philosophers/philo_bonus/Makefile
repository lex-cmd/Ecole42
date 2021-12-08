FLAGS 	=	-Werror -Wextra -Wall
NAME 	=	philo_bonus
SRC 	=	philo_bonus.c first_part_philo_bonus.c time_usleep_bonus.c philo_two_bonus.c utils_bonus.c ft_atoi_bonus.c ft_putstr_fd_bonus.c
OBJ		=	$(SRC:.c=.o)
HEAD	=	philo_bonus.h

all : $(NAME)


$(NAME) : $(OBJ) $(HEAD)
	gcc $(SRC) -o $(NAME) -I

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

p:
	git add .
	git status
	git commit -m pipe
	git push origin main