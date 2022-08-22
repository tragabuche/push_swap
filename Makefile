# By: mpascual <mpascual@42madrid.student.com>

NAME		= push_swap
LIBFT_DIR	= ./libft
LIBFT		= libftprintf.a
LIBFT_HEAD	= $(LIBFT_DIR)/header.h
HEADER		= pushswap.h
SRCS		= pushswap.c arg_filter.c

OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall #-Wextra -Werror

all: compile_libft $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)

compile_libft:
	cd $(LIBFT_DIR) && make

clean:
	rm -rf $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_DIR)/$(LIBFT)

re: fclean all

norme: clean
	@norminette $(SRC)

.PHONY: all clean fclean re
