NAME		= ft_select

FILES		= main.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

LIBFT		= ./libft
HEADERS		= .

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
