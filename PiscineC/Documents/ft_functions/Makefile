# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 13:54:33 by dtedgui           #+#    #+#              #
#    Updated: 2015/08/18 19:53:36 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs

DIR		= ./SOURCES
HEADERS	= .
SRC		= $(OBJ:.o=.c)
OBJ		= ft_atoi.o \
		  ft_power.o \
		  ft_putchar.o \
		  ft_putnbr.o \
		  ft_putstr.o \
		  ft_range.o \
		  ft_sort_integer_table.o \
		  ft_sqrt.o \
		  ft_strcapitalize.o \
		  ft_strcat.o \
		  ft_strcmp.o \
		  ft_strcpy.o \
		  ft_strdup.o \
		  ft_strlen.o \
		  ft_strlowcase.o \
		  ft_strrev.o \
		  ft_strstr.o \
		  ft_strupcase.o \
		  ft_swap.o \

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -I $(HEADERS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
