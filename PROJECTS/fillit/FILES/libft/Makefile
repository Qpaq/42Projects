NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs

SRC		= ft_putchar.c ft_putendl.c \
		  ft_strjoin.c ft_strncpy.c ft_strndup.c \
		  ft_strnew.c ft_strlen.c get_next_line.c \
		  ft_bzero.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
