# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/20 13:46:13 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/20 14:31:22 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file

CFLAGS	= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)
SRC		= main.c \
		  ft_display_file.c

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $(CFLAGS) $^ -I .

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $^ -I .

clean:
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)

re: fclean all
