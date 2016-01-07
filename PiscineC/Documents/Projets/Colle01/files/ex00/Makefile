NAME	= sudoku

CFLAGS	= -Wall -Werror -Wextra

SRC		= main.c sudoku.c check.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $^

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $^
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
