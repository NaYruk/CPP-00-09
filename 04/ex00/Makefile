PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m

CC = g++
INCLUDES = -I./includes
FLAGS = -Wall -Wextra -Werror $(INCLUDES) -std=c++98
SRC = ./sources/main.cpp ./sources/Animal.cpp ./sources/Dog.cpp ./sources/Cat.cpp ./sources/WrongCat.cpp ./sources/WrongAnimal.cpp

OBJ = $(SRC:%.cpp=%.o)
NAME = Polymorphism
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