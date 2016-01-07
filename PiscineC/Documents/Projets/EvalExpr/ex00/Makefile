# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/22 12:26:50 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/22 12:31:06 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= EVAL_EXPR

CFLAGS	= -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)
SRC		= main.c \
		  eval_expr.c \
		  basic_functions.c \
		  operators.c \

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $(CFLAGS) -I . $^

$(OBJ): $(SRC)
	gcc -c $(CFLAGS) $(SRC) -I .

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
