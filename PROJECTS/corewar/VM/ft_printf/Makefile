# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abungert <abungert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/28 16:04:57 by abungert          #+#    #+#              #
#    Updated: 2016/05/16 15:49:30 by amanukya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES	= ft_printf.c \
		  parse_tag.c \
		  get_converter.c \
		  converters/convert_int.c \
		  converters/convert_unsigned_int.c \
		  converters/convert_octal.c \
		  converters/convert_hexa.c \
		  converters/convert_char.c \
		  converters/convert_string.c \
		  converters/convert_address.c \
		  converters/convert_escape.c \
		  converters/convert_long.c \
		  converters/convert_wchar.c \
		  converters/convert_wstring.c \
		  converters/convert_binary.c \
		  color.c \
		  utils/print_width_pad.c \
		  utils/nbr_strlen.c \
		  utils/print_forceprefix.c \
		  utils/convert_length.c \
		  utils/print_forceprefix_max.c \
		  utils/print_uint.c

SRC		= $(addprefix srcs/, $(FILES))
OBJ		= $(SRC:.c=.o)

INC     = ./includes
LIBFT	= ./libft

CC		= gcc
AR      = ar
ARFLAGS = rcs

ifdef FLAGS
    ifeq ($(FLAGS), no)
        CFLAGS	= 
    endif
    ifeq ($(FLAGS), debug)
        CFLAGS	= -Wall -Wextra -Werror -g
    endif
else
    CFLAGS      = -Wall -Wextra -Werror
endif

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@$(AR) r $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ $(CFLAGS) -I $(INC) -c $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
