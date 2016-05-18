/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:37:44 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:38:03 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "op.h"

# define LIVE		1
# define LD			2
# define ST			3
# define ADD		4
# define SUB		5
# define AND		6
# define OR			7
# define XOR		8
# define ZJMP		9
# define LDI		10
# define STI		11
# define FORK		12
# define LLD		13
# define LLDI		14
# define LFORK		15
# define AFF		16

# define FILE_MAX_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 16)

typedef struct	s_arg
{
	int		count;
	int		types[MAX_ARGS_NUMBER];
	int		values[MAX_ARGS_NUMBER];
}				t_arg;

typedef struct	s_process
{
	int					reg[REG_NUMBER];
	int					pc;
	char				carry;
	int					num;
	int					cycles_to_wait;
	int					is_waiting;
	int					waiting_op;
	int					live;
	struct s_process	*next;
	struct s_process	*prev;

}				t_process;

typedef struct	s_champion
{
	char			*name;
	char			*comment;
	unsigned char	*data;
	int				data_len;
	int				number;
	int				live;
}				t_champion;

typedef struct	s_vm
{
	int					dump_cycle;
	t_champion			champions[MAX_PLAYERS];
	int					cycle_to_die;
	int					lives_in_current_period;
	int					champ_nb;
	int					cycle_in_current_period;
	int					last_champion_alive_number;
	char				*last_champion_alive_name;
	int					nb_process;
	struct s_process	*process;
	unsigned char		memory[MEM_SIZE];
}				t_vm;

void			check_errors(int argc, char **argv);
void			check_cor_files(int ac, char **av);
int				read_and_check_comment(int fd);
int				read_and_check_name(int fd);
int				read_and_check_magic(int fd);
void			check_champion_number(t_vm *vm);

void			init_vm(t_vm *vm);
void			init_champ(t_vm *vm);
void			get_vm(t_vm *vm, char **argv, int argc);

void			load_champions(t_vm *vm);
void			hexdump(unsigned char *data, size_t size);

void			start_running_vm(t_vm *vm);
void			write_byte(long value, t_vm *vm, long number,
							t_process *process);
long			get_value_depending_on_type(int pos, t_arg *args,
											t_process *process, t_vm *vm);
int				get_int_from_bytes(t_vm *vm, t_process *process, int addr);
int				get_int_from_two_bytes(t_vm *vm, t_process *process, int addr);
int				ft_check_reg_exist(t_arg *args);
int				handle_coding_byte(int cursor, t_vm *vm, int op);
int				ft_loop_memory(int value);

void			ft_live(t_arg *args, t_vm *vm, t_process *process);
void			ft_st(t_arg *args, t_vm *vm, t_process *process);
void			ft_add(t_arg *args, t_vm *vm, t_process *process);
void			ft_sub(t_arg *args, t_vm *vm, t_process *process);

void			(*g_fct_ptr[16])(t_arg *, t_vm *, t_process *);

/*
** INSTRUCTIONS
*/
void			ft_live(t_arg *args, t_vm *vm, t_process *process);
void			ft_ld(t_arg *args, t_vm *vm, t_process *process);
void			ft_st(t_arg *args, t_vm *vm, t_process *process);
void			ft_add(t_arg *args, t_vm *vm, t_process *process);
void			ft_sub(t_arg *args, t_vm *vm, t_process *process);
void			ft_and(t_arg *args, t_vm *vm, t_process *process);
void			ft_or(t_arg *args, t_vm *vm, t_process *process);
void			ft_xor(t_arg *args, t_vm *vm, t_process *process);
void			ft_zjmp(t_arg *args, t_vm *vm, t_process *process);
void			ft_ldi(t_arg *args, t_vm *vm, t_process *process);
void			ft_sti(t_arg *args, t_vm *vm, t_process *process);
void			ft_lld(t_arg *args, t_vm *vm, t_process *process);
void			ft_lldi(t_arg *args, t_vm *vm, t_process *process);
void			ft_fork(t_arg *args, t_vm *vm, t_process *process);
void			ft_lfork(t_arg *args, t_vm *vm, t_process *process);
void			ft_aff(t_arg *args, t_vm *vm, t_process *process);

/*
** CHECK_STATE
*/
void			ft_kill_champ(t_vm *vm, int to_kill);
void			ft_finish(t_vm *vm);
void			ft_check_alive(t_vm *vm);
void			free_first(t_vm *vm, t_process **tmp);
void			free_middle(t_process **tmp);
void			free_last(t_process **tmp);

/*
** VM_GET_ARGS
*/
int				get_label_size(int op);
int				get_argument_type(char *bin);
void			get_op_args_values(t_vm *vm, t_process *process,
									int op, t_arg *args);
void			get_op_args_types(t_vm *vm, t_process *process,
									int op, t_arg *args);
t_arg			*get_op_args(t_vm *vm, t_process *process, int op);

#endif
