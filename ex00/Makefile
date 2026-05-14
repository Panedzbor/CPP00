COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = megaphone
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

