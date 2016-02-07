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
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT) -lft
	@echo "\033[1;32m$@ COMPILED ✓\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: \033[34m$@\033[0m"

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
