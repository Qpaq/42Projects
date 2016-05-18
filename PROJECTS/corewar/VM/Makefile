NAME		= corewar

FILES		= corewar.c \
 			  check_errors.c \
 			  init_vm.c \
 			  get_vm.c \
			  load_champions.c \
			  virtual_machine.c \
			  vm_check_state.c \
			  vm_get_args.c \
			  hexdump.c \
			  utils.c \
			  get_from_memory.c \
			  instructions1.c \
			  instructions2.c \
			  instructions3.c \
			  instructions4.c \
			  free.c \
			  check_header.c \
			  check_header2.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

FT_PRINTF	= ./ft_printf

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g

INCLUDES	= -I$(FT_PRINTF)/includes -I.
CFLAGS		+= $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(FT_PRINTF)/libftprintf.a
	@echo "\033[1;32m$@ COMPILED ✓\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C $(FT_PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all
