.PHONY: 		clean fclean re norm

NAME = so_long

CC = gcc 

ifeq ($(shell uname),Linux)
   # Linux-specific commands
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
	CFLAGS = -Wall -Wextra -Werror -ggdb -g3
endif


SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

PRINT_A		= libftprintf.a
PRINT_DIR 	= ft_printf/
PRINT		= $(addprefix $(PRINT_DIR), $(PRINT_A))

MLX_A		= libmlx.a
MLX_DIR 	= mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))

INCLUDE		= so_long.h

SRC = $(SRC_DIR)/game/ft_game_init.c \
	  $(SRC_DIR)/game/ft_open_img.c \
	  $(SRC_DIR)/game/ft_put_sprite.c \
	  $(SRC_DIR)/game/ft_sprite_map.c \
	  $(SRC_DIR)/game/ft_move.c \
	  $(SRC_DIR)/game/ft_take_objects.c \
	  $(SRC_DIR)/game/ft_update.c \
	  $(SRC_DIR)/game/ft_utils.c \
	  $(SRC_DIR)/game/ft_checks.c \
	  $(SRC_DIR)/parsing/ft_init_map.c \
      $(SRC_DIR)/parsing/ft_check_wall.c \
      $(SRC_DIR)/parsing/ft_check_item.c \
      $(SRC_DIR)/parsing/ft_create_map.c \
      $(SRC_DIR)/parsing/ft_map_info.c \
      $(SRC_DIR)/parsing/ft_way_is_ok.c \
      $(SRC_DIR)/main.c \


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: 
	make -C $(LIBF_DIR)
	make -C $(PRINT_DIR)
	make $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINT) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ)  $(PRINT) $(MLXFLAGS) $(MLX) -o $(NAME) $(LIBFT)
	echo "\033[1;34mCompilation terminée avec succès ! ✔️\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)/parsing $(OBJ_DIR)/game
	$(CC) $(CFLAGS) -I mlx -c $< -o $@

norm:
	@if ! norminette ./game ./parsing ./libft ./ft_printf | grep -v "OK" > /dev/null; then \
 		echo "\033[1;32mNorminette valide ! ✔️\033[0m"; \
 	else \
 		norminette ./game ./parsing ./libft ./ft_printf | grep -v "OK" | grep --color=always "Error"; \
 	fi

clean:
	@echo "\033[1;33mSuppression des fichiers objets... \033[0m🗑"
	make clean -C $(LIBF_DIR)
	make clean -C $(PRINT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[1;33mSuppression du programme final... \033[0m🗑"
	make fclean -C $(LIBF_DIR)
	make fclean -C $(PRINT_DIR)
	@rm -f $(NAME)

re: fclean all norm
