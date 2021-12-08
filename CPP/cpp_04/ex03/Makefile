SRCS			= main.cpp AMateria.cpp Character.cpp MateriaSource.cpp Cure.cpp Ice.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= AMateria.hpp Character.hpp ICharacter.hpp Cure.hpp Ice.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp
CPP				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= magic

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
