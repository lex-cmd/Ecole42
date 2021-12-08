SRCS			= main.cpp Cat.cpp Dog.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= Cat.hpp Dog.hpp Animal.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
CPP				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= animal

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
