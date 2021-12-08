FLAGS 	=	-Werror -Wextra -Wall
NAME 	=	philo
SRC 	=	philo.c first_part_philo.c time_usleep.c \
			philo_two.c utils.c philo_life.c\
			ft_atoi.c ft_putstr_fd.c
OBJ		=	$(SRC:.c=.o)
HEAD	=	philo.h

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