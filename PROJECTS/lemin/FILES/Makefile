NAME		= lem-in

FILES		= main.c \
			  save_paths.c \
			  get_room_infos.c \
			  close_list.c \
			  open_list.c \
			  create_rooms.c \
			  move.c \
			  move2.c \
			  parsing.c 

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

FT_PRINTF	= ./ft_printf

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= -I$(FT_PRINTF)/includes -I.
CFLAGS		+= $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF)/libftprintf.a
	@echo "LEMIN compiled"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all
