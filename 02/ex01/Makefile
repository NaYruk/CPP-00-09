PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ./main.cpp ./Fixed.cpp

OBJ = $(SRC:%.cpp=%.o)
NAME = Utile_class

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ)

fclean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all

.PHONY: NAME all clean fclean re