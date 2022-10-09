# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 18:51:54 by mpascual          #+#    #+#              #
#    Updated: 2022/10/09 22:25:35 by mpascual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output Colors
CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

# Global Config
NAME		= push_swap
LIBFT_DIR	= ./libft
LIBFT		= libft.a
LIBFT_HEAD	= $(LIBFT_DIR)/header.h
HEADER		= pushswap.h
SRC_FILES	= pushswap.c arg_filter.c instructions.c small_sort.c utils.c \
			  debug.c
BONUS_SRC	= 
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

ifdef WITH_BONUS
SRC = $(SRC_FILES) $(BONUS_SRC)
else
SRC = $(SRC_FILES)
endif

OBJS		= $(SRC:%.c=%.o)

all: compile_libft $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

compile_libft:
	cd $(LIBFT_DIR) && $(MAKE)

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re: fclean all

norme: clean
	@norminette $(SRC)

bonus:
	$(MAKE) WITH_BONUS=1

.PHONY: all clean fclean re
