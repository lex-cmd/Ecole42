FLAGS 	=	-Wall -Wextra -Werror
NAME 	=	bsp
SRC 	=	Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ		=	$(SRC:.c=.o)
HEAD	= 	Fixed.hpp Point.hpp

all : $(NAME)

%.o: %.c $(HEAD)
	c++ -std=c++98 $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ) $(HEAD)
	c++ -std=c++98 $(FLAGS) $(SRC) -o $(NAME) $(FRAEMWORKS) -I

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

p:
	git add .
	git status
	git commit -m mish
	git push origin master

.PHONY : clean fclean re
