# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 12:31:52 by cwannhed          #+#    #+#              #
#    Updated: 2025/12/01 15:17:52 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

SRC = megaphone.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)
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