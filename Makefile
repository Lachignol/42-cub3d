NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MAKEFLAGS += --no-print-directory

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
RESET = \033[0m

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = minilibx-linux
GLIBFT_DIR = g_libft

# Include (.h)
SUBGLIBFT_DIRS = $(shell find $(GLIBFT_DIR) -type d)
INCLUDES = $(addprefix -I, $(INC_DIR) $(SUBGLIBFT_DIRS) $(MLX_DIR))

# Libraries
GLIBFT_FILE = $(GLIBFT_DIR)/libft.a
MLX_FILE = $(MLX_DIR)/libmlx.a
# Links
GLIBFT_LINK = -L$(GLIBFT_DIR) -lft
MLXLIB_LINK = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Sources
SRC = $(shell find $(SRC_DIR) -name "*.c")

# Objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@echo "$(BLUE)Compiling:$(RESET) $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(GLIBFT_FILE) $(MLX_FILE) $(NAME)
only_cub3d: $(NAME)

$(GLIBFT_FILE):
	@make -C $(GLIBFT_DIR)

$(MLX_FILE):
	@echo "$(YELLOW)Building & linking $(MLX_FILE)...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null
	@echo "$(GREEN)$(MLX_FILE) is ready!$(RESET)"

$(NAME): echo_building_name $(OBJ)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(GLIBFT_LINK) $(MLXLIB_LINK) -o $(NAME)
	@echo "$(GREEN)$(NAME) is ready!$(RESET)"

echo_building_name:
	@echo "$(YELLOW)Building $(NAME)...$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@echo "Cleaning mlx object files & removing library..."
	@make clean -C $(GLIBFT_DIR)
	@make clean -C $(MLX_DIR) > /dev/null
	@echo "Cleaning cub3d object files..."
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean:
	@echo "$(YELLOW)Full cleaning...$(RESET)"
	@echo "Cleaning mlx object files & removing library..."
	@make clean -C $(MLX_DIR) > /dev/null
	@make fclean -C $(GLIBFT_DIR)
	@echo "Cleaning cub3d object files..."
	@rm -rf $(OBJ_DIR)
	@echo "Removing cub3d executable..."
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(RESET)"

fclean_only_cub3d:
	@echo "$(YELLOW)Full cleaning...$(RESET)"
	@echo "Cleaning cub3d object files..."
	@rm -rf $(OBJ_DIR)
	@echo "Removing cub3d executable..."
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all
sre: fclean_only_cub3d only_cub3d

.PHONY: all clean fclean re echo_building_name only_cub3d fclean_only_cub3d sre
