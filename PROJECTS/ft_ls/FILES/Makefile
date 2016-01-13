# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/28 11:02:45 by dtedgui           #+#    #+#              #
#    Updated: 2016/01/13 15:55:11 by dtedgui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= ft_ls

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.

FILES	= main.c \
		  get_arguments.c \
		  browse_directory.c \
		  get_file_info.c \
		  print_dir.c \
		  errors.c

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
