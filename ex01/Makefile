COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = Contact.hpp PhoneBook.hpp
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $^

%.o: %.cpp $(INCLUDES)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

