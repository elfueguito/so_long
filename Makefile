.PHONY : all clean fclean re libft ftprintf mlx

CC = cc
CFLAGS = -Wall -Wextra -Werror

SO_LONG_HEADERS = so_long.h
NAME = so_long
SRCS_SO_LONG = 	parsing/ft_check_wall.c \
				parsing/ft_create_map.c \
				parsing/ft_check_item.c \
				parsing/ft_map_info.c \
				parsing/ft_way_is_ok.c \
				ft_render.c \

LIST_OBJS_SO_LONG = $(SRCS_SO_LONG:.c=.o) 

#-----------------------------------#

LIBFT_HEADERS = Libft/libft.h
NAME_LIBFT = Libft/libft.a

#-------------------------------------#

FT_PRINTF = ft_printf/ft_printf.h
NAME_FT_PRINTF = ft_printf/libftprintf.a

#-------------------------------------#

MLX_DIR = ./mlx/
MLX = mlx/mlx.h
NAME_MLX = mlx/libmlx.a
MFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#--------------------------------------#

DIR_HEADERS = .
DIR_OBJS_SO_LONG = objs/

#---------------------------------------------------------------#

OBJS_SO_LONG = $(addprefix $(DIR_OBJS_SO_LONG), $(LIST_OBJS_SO_LONG))

$(NAME): libft ftprintf mlx $(OBJS_SO_LONG) $(SO_LONG_HEADERS) Makefile
	@$(CC) $(CFLAGS) -o $(NAME) -I $(DIR_HEADERS) -I . -I $(SO_LONG_HEADERS) -I Libft $(NAME_LIBFT) -I ftprintf $(NAME_FT_PRINTF)  -I mlx $(MFLAGS) $(NAME_MLX) -o $(NAME) $(OBJS_SO_LONG)
#	@$(CC) $(CFLAGS) -o $(OBJS_SO_LONG) $(MFLAGS) $(NAME_MLX) -o $(NAME)

$(DIR_OBJS_SO_LONG)%.o: %.c $(SO_LONG_HEADERS) Makefile
	mkdir -p $(DIR_OBJS_SO_LONG)/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@ -I $(DIR_HEADERS)
# $(DIR_OBJS):
# 	mkdir -p $(DIR_OBJS_SO_LONG)

libft: FORCE
	@make -C Libft

ftprintf: FORCE
	@make -C ft_printf

mlx: FORCE
	@make -C mlx

FORCE:

all: $(NAME)

#-----------------------------------------------------------------#

clean:
	@rm -rf $(DIR_OBJS_SO_LONG) $(OBJS) 
	@make clean -C Libft
	@make clean -C ft_printf
	@make clean -C mlx

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C Libft
	@make fclean -C ft_printf
	@make clean -C mlx
	
re:  clean fclean 
	@$(MAKE) all
