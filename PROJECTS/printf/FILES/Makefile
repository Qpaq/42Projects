# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/05 14:22:12 by abungert          #+#    #+#              #
#    Updated: 2016/01/10 15:39:25 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

FILES	= main.c \
		  ft_printf.c \
		  parse_tag.c \
		  get_handler.c \
		  handlers.c

SRC		= $(addprefix srcs/, $(FILES))
OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.

#ifdef FLAGS
#    ifeq ($(FLAGS), no)
#        CFLAGS	= -c -I.
#    endif
#    ifeq ($(FLAGS), debug)
#        CFLAGS	= -c -I. -Wall -Wextra -Werror -ansi -pedantic -g
#    endif
#else
#    CFLAGS      = -c -I. -Wall -Wextra -Werror
#endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) -o $@ $(CFLAGS) $^ -L$(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean


re: fclean all
