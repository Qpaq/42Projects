NAME		= ft_select

FILES		= main.c \
			  terminal.c \
			  signals.c \
			  get_key.c \
			  key_actions.c \
			  list.c \
			  utils.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)
	
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

FT_PRINTF	= ./ft_printf

INCLUDES	= -I$(FT_PRINTF)/includes -I.
CFLAGS		+= $(INCLUDES)

LIBS		= -ltermcap -L$(FT_PRINTF) -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "\033[1;32m$@ COMPILED ✓\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: \033[34m$@\033[0m"

clean:
	rm -f $(OBJ)
	@make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all

git: fclean
	git add .
	@echo "Enter your commit message: "
	@read commit_ftselect ; git commit -m "ft_select: $$commit_ftselect"
	git push
