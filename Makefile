NAME		= push_swap
LIBFT		= libftprintf.a
LIBFT_DIR	= ./libftprintf/
SRCS		= pushswap.c

OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: make