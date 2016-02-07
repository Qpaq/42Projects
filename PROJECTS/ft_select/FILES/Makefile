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

git: fclean
	git add .
	@echo "Enter your commit message: "
	@read commit_ftselect ; git commit -m "$$commit_ftselect"
	git push
