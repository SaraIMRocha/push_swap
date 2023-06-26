# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sara <sara@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 02:50:08 by sara              #+#    #+#              #
#    Updated: 2023/06/26 01:22:37 by sara             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ./srcs/check.c \
		./srcs/check_utils.c \
		./srcs/init.c \
		./srcs/main.c \
		./srcs/cost.c \
		./srcs/place.c \
		./srcs/push.c \
		./srcs/reverse.c \
		./srcs/rotate.c \
		./srcs/small_sort.c \
		./srcs/sorting.c \
		./srcs/stack.c \
		./srcs/swap.c \
		./srcs/utils.c \
		./srcs/which_move.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -f

#colors
RESET			:= \033[0m
GREEN			=	\e[32m
YELLOW			=	\e[033m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Objects created!$(RESET)"

clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)$(BOLD)Push_Swap Deleted!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.PHONY: all clean fclean re

.SILENT:

