PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m

# Compiler and flags
CXX = c++
CPPFLAGS = -I./includes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

# Sources
SRC = ./sources/main.cpp

# Objects
OBJ = $(SRC:%.cpp=%.o)

# Target
NAME = Templates

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Compile .cpp -> .o (ensure flags are applied during compilation)
%.o: %.cpp
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: NAME all clean fclean re