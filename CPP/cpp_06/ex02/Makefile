SRCS			= main.cpp Base.cpp
OBJS			= $(SRCS:.cpp=.o)
HEAD			= Base.hpp A.hpp B.hpp C.hpp
CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= Identify

all:			$(NAME) $(HEAD)

$(NAME):		$(OBJS) $(HEAD)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test
