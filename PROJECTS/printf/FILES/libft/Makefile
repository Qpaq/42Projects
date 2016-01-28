NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar
ARFLAGS	= rcs

SRC		=	ft_putchar.c ft_putwchar.c ft_putchar_fd.c ft_putstr.c ft_putnstr.c ft_putstr_fd.c \
			ft_putwstr.c ft_putnwstr.c ft_putendl.c ft_putendl_fd.c ft_putcolor.c ft_putrainbow.c \
			ft_putstr_array.c \
			ft_putnbr.c ft_putnbr_fd.c ft_putnbr_base.c \
			ft_atoi.c ft_atoi_base.c ft_itoa.c ft_itoa_base.c \
			ft_power.c ft_sqrt.c ft_sort_integer_table.c \
			ft_tolower.c ft_toupper.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memalloc.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_mem_realloc.c \
			ft_strlen.c ft_strlen_char.c ft_bzero.c ft_strnew.c ft_strclr.c ft_strdel.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strndup.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
			ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c \
			ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
			ft_strjoin.c ft_strsub.c ft_strsplit.c ft_strtrim.c ft_strrev.c \
			ft_lstadd_beginning.c ft_lstadd_end.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			get_next_line.c ft_max.c ft_strnlen.c ft_strwlen.c ft_strnwlen.c

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
