# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 11:18:26 by dtedgui           #+#    #+#              #
#    Updated: 2015/12/20 10:57:35 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

LIBFT	= ./libft

SRC		= main.c \
		  check_file.c \
		  fillit_algo.c \
		  check_tetri.c

OBJ		= $(SRC:.c=.o)

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
