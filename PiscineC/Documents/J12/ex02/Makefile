# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/20 15:23:24 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/20 15:28:40 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_tail

CFLAGS	= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)
SRC		= ft_tail.c \
		  main.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $^ -I .

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $^ -I .

clean:
	rm -f *.o

fclean: clean
	rm -r $(NAME)

re: fclean all
