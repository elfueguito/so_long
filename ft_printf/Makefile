.PHONY : all clean fclean re

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = ft_printf.h
SRCS = ft_printf.c \
	ft_utils.c \
	ft_itoa.c \
	ft_print_hex.c \
	ft_print_hex_up.c \
	ft_print_ptr.c \
	ft_print_unsigned.c \
	
LIST_OBJS = $(SRCS:.c=.o)

DIR_HEADERS = ./
DIR_OBJS = objs/

OBJS = $(addprefix $(DIR_OBJS), $(LIST_OBJS))

$(NAME): $(DIR_OBJS) $(OBJS) $(LIST_HEADERS) Makefile
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(DIR_OBJS)%.o: %.c $(LIST_HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

clean:
	rm -rf $(DIR_OBJS) $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)