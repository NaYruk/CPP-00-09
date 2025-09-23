# EMOJIS
PROGRESS = \033[33m⏳\033[0m
BROOM = \033[33m🧹\033[0m
SUCCESS = \033[32m✔\033[0m



#Compiler
CXX = g++

#include folder(s)
INCLUDES = -I./includes

#Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 $(INCLUDES)

#Source files folder
SRC_FOLDER = ./sources
#Source files
SRCS = 	$(SRC_FOLDER)/main.cpp \
		$(SRC_FOLDER)/RPN.cpp \

#Object folder
OBJ_DIR = ./obj
#Object files
OBJS = $(SRCS:$(SRC_FOLDER)%.cpp=$(OBJ_DIR)%.o)

#Name of the executable
NAME = RPN




# Default rule to build an executable
all: $(NAME)

# Rule to link object files into the executable
$(NAME): $(OBJS)
	@echo "\n$(PROGRESS) Compilation start ! $(PROGRESS)\n"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\n$(SUCCESS) Compilation Finished ! $(SUCCESS)\n"

# Rule to compile .cpp files into .o files or Create the Object Directory if is not here
$(OBJ_DIR)/%.o: $(SRC_FOLDER)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the Object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)




# Rule for clean the .o files
clean:
	@echo "\n$(BROOM) Cleaning !!! $(BROOM)\n"
	@rm -rf $(OBJ_DIR)

# Rule for clean the .o files and the executable
fclean: clean
	@rm -rf $(NAME)

# Rule for fclean and reMake the project
re: fclean all




# Avoid files with the same name as the rules
.PHONY: clean fclean re all $(NAME)
	

