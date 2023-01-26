.PHONY: all clean fclean re

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm


SRC_DIR = .
OBJ_DIR =  ./objs/

LIBFT_A		= libft.a
LIBF_DIR 	= Libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

PRINTF_A	= libftprintf.a
PRINTF_DIR 	= ft_printf/
PRINTF		= $(addprefix $(PRINTF_DIR), $(PRINTF_A))

MLX_A		= libmlx.a
MLX_DIR 	= mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))

SRC = 	$(SRC_DIR)/parsing/ft_check_wall.c \
		$(SRC_DIR)/parsing/ft_create_map.c \
		$(SRC_DIR)/parsing/ft_check_item.c \
		$(SRC_DIR)/parsing/ft_map_info.c \
		$(SRC_DIR)/parsing/ft_way_is_ok.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(MLX) -o $(NAME)
	@echo "\033[1;34mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/create_map $(OBJ_DIR)/gnl $(OBJ_DIR)/game
	@$(CC) $(CFLAGS) -I. mlx -c $< -o $@

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	@rm -f $(NAME)

re: fclean all