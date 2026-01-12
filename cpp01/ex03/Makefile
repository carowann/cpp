# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 11:32:05 by cwannhed          #+#    #+#              #
#    Updated: 2026/01/12 12:28:15 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz

CC = c++

SRC = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp

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