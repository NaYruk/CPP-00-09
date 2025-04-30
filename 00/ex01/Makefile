PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m

CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ./main.cpp ./PhoneBook.cpp ./Contact.cpp

OBJ = $(SRC:%.cpp=%.o)
NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(PROGRESS) Compiled in progress $(PROGRESS)...\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(SUCCESS) Compiling is finished $(SUCCESS) !!!"

clean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ)

fclean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all

.PHONY: NAME all clean fclean re