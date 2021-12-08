SRCS			= main.cpp Bureaucrat.cpp Form.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= Bureaucrat.hpp Form.hpp
CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= Bureaucrat

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
