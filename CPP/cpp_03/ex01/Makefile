SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= ClapTrap.hpp ScavTrap.hpp
CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= serena

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
