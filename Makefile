# By: mpascual <mpascual@42madrid.student.com>

NAME		= push_swap
LIBFT_DIR	= ./libft
LIBFT		= libftprintf.a
LIBFT_HEAD	= $(LIBFT_DIR)/header.h
HEADER		= pushswap.h
SRCS		= pushswap.c arg_filter.c instructions.c

OBJS		= $(SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: compile_libft $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)

compile_libft:
	cd $(LIBFT_DIR) && make

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re: fclean all

norme: clean
	@norminette $(SRCS)

leaks: $(NAME) clean
	@leaks $(NAME)

.PHONY: all clean fclean re
