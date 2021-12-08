SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wshadow -Wno-shadow -Wall -Wextra -Werror -I.

NAME			= DiamondTrap

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
