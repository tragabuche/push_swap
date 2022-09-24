# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 20:46:54 by mpascual          #+#    #+#              #
#    Updated: 2022/09/24 22:05:52 by mpascual         ###   ########.fr        #
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
NAME 		= libft.a
CFLAGS 		= -Wall -Werror -Wextra
SRC_FILES	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c \
			  ft_calloc.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memcmp.c\
			  ft_memmove.c ft_memset.c ft_putchar_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
			  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			  ft_strmapi.c ft_strncmp.c\
			  ft_strnstr.c ft_strrchr.c \
			  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			  ft_putchar.c ft_putstr.c \
			  ft_itoa.c ft_nbrlen.c ft_putnbr.c get_next_line.c
BONUS_SRC	= $(SRC_FILES) ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			  ft_lstsize_bonus.c
HEADER		= libft.h

ifdef WITH_BONUS
	SRC = $(SRC_FILES) $(BONUS_SRC)
else
	SRC = $(SRC_FILES)
endif

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

OBJ :
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	gcc -c $(CFLAGS) $(OBJ)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "$(GREEN)$(NAME) created ✓${CLR_RMV}"

bonus :
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ)
	rm -f $(subst .c,.o,$(BONUS_SRC))

fclean: clean
	rm -f $(NAME)

re: fclean all

norme: fclean
	@norminette

.PHONY: clean fclean all re
