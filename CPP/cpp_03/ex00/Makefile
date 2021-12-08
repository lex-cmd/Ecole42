SRCS			= main.cpp ClapTrap.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= ClapTrap.hpp
CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= open

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
