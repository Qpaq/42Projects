# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 13:54:33 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/18 19:51:54 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
OPTIONS = -I $(HEADERS)
AR		= ar
ARFLAGS	= rcs

DIR		= ./srcs
HEADERS	= ./includes
SRC		= $(OBJ:.o=.c)
OBJ		= ft_putchar.o \
		  ft_putstr.o \
		  ft_strcmp.o \
		  ft_strlen.o \
		  ft_swap.o \


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: $(DIR)/%.c 
	$(CC) $(CFLAGS) -c $^ $(OPTIONS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
