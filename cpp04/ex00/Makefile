# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 16:10:30 by cwannhed          #+#    #+#              #
#    Updated: 2026/02/11 18:05:37 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

CC = c++

SRC = main.cpp \
	Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	$(CC) $(SRC) $(CXXFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"
	@echo "$(CYAN)Run with: ./$(NAME)$(RESET)"

clean:
	@echo "$(BLUE)Cleaning up...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleanup complete!$(RESET)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re

# Colors
RESET = \033[0m
BLUE = \033[34m
GREEN = \033[32m
CYAN = \033[36m