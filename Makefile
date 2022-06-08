# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chajjar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 19:10:06 by chajjar           #+#    #+#              #
#    Updated: 2022/06/07 18:20:22 by chajjar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OPTIONS #

NAME = push_swap

SRC = swap.c push.c rotate.c reverse_rotate.c \
	  main.c utils.c process_small.c utils_smal.c \
	  parsing.c push_swap.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

# RULES #

all: $(NAME)

dependency:
	@make -sC Libft

.c.o:
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): dependency $(OBJ)
	@gcc $(DANGER) -o $(NAME) $(OBJ) -LLibft -lft

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

aclean: fclean
	@make fclean -sC Libft

re: aclean all

test: all
	@./$(NAME)
	@make fclean

# PROTECTION #

.PHONY: all dependency clean fclean aclean re
