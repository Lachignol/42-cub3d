# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoger <aoger@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:56:16 by aoger             #+#    #+#              #
#    Updated: 2025/03/13 18:23:18 by aoger            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
RESET = \033[0m

FTSTD_DIR = ft_std
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

all: $(NAME)

$(NAME):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(FTSTD_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(FTSTD_DIR)/obj/*/*.o $(PRINTF_DIR)/obj/*/*.o $(GNL_DIR)/obj/*/*.o
	@echo "$(GREEN)Libft ready!$(RESET)"

clean:
	@echo "Cleaning libft object files..."
	@make clean -C $(FTSTD_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@echo "Removing libft library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
