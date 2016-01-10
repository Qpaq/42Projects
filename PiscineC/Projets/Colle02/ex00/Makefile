# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/22 16:45:03 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/23 18:57:33 by alhote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= colle-2

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

HEADER	= -I .
OBJ		= $(SRC:.c=.o)
SRC		= main.c \
		  colle.c \
		  check.c \
		  basic_functions.c \

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(HEADER)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^ $(HEADER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
