# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 11:02:45 by dtedgui           #+#    #+#              #
#    Updated: 2015/12/30 18:58:25 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= a.out

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.

FILES	= main.c \
		  get_arguments.c \
		  browse_directory.c \
		  get_file_info.c

LIBFT	= ./libft

SRC		= $(addprefix srcs/, $(FILES))
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
