# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 10:49:48 by dtedgui           #+#    #+#              #
#    Updated: 2015/12/21 18:49:14 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= alum1

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRC		= main.c \
		  players_entry.c \
		  init_game.c \
		  get_next_line.c \
		  algo.c

OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -L$(LIBFT) -lft $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
