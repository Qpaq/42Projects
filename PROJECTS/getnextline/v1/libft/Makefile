NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar
ARFLAGS	= rcs

SRC		= ft_strjoin.c \
		  ft_strlen.c \
		  ft_strndup.c \
		  ft_strnew.c \
		  ft_strncpy.c \
		  ft_bzero.c \
		  ft_putendl.c

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
