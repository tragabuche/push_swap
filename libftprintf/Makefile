# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 17:01:42 by mpascual          #+#    #+#              #
#    Updated: 2022/09/24 19:25:43 by mpascual         ###   ########.fr        #
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
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = src/ft_printf.c src/utils.c src/print_cs.c src/print_di.c \
		src/print_xp.c src/print_u.c
OBJS = $(SRC:%.c=%.o)

$(NAME): $(OBJS)
	cd libft && make
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

norme: fclean
	@norminette ./libft/
	@norminette ./src/
	@norminette ./header.h

all: $(NAME)

clean:
	rm -rf $(OBJS)
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all

.PHONY: fclean
