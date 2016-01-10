# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/19 18:39:39 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/19 19:01:28 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

NAME	= do-op
HEADER	= .
SRC		= main.c \
		  do_op.c \
		  operators.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $@ $(SRC) -I $(HEADER)

clean:
	rm -f $(NAME)
