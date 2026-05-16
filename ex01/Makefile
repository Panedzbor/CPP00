COMPILER = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

NAME = phonebook
SRCS = $(wildcard *.cpp)
OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
INCLUDES = Contact.hpp PhoneBook.hpp
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

