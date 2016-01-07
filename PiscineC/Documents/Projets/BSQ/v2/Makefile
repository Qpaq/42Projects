# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/24 09:55:02 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/27 11:56:10 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)
SRC		= main.c \
		  bsq.c \
		  get_grid.c \
		  basic_functions.c \
		  check_grid.c \
		  freetabs.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
