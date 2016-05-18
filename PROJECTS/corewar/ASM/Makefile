NAME		= asm

FILES		= main.c \
			  get_cor_file.c \
			  get_header.c \
			  get_instructions.c \
			  write_to_cor.c \
			  write_to_cor2.c \
			  get_inst_infos.c \
			  get_inst_infos2.c \
			  parse_file.c \
			  ft_error.c \
			  check_nc.c \
			  line_kind.c \
			  check_instr.c \
			  get_new_label.c \
			  get_kind_arg.c \
			  check_label_connections.c \
			  init_free.c \
			  end_nc.c \
			  check_size_nc.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

FT_PRINTF	= ./ft_printf

INC			= -I$(FT_PRINTF)/includes -I.

CC			= gcc

ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS = 
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS = -Wall -Wextra -Werror -g
	endif
else
	CFLAGS	= -Wall -Werror -Wextra
endif

CFLAGS		+= $(INC)

LIBS 		= ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) -ltermcap
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
