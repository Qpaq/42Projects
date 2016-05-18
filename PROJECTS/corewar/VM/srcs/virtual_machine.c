/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:41:34 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:38 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	exec_action(t_vm *vm, t_process *process, int op)
{
	t_arg	*args;

	args = get_op_args(vm, process, op);
	if (op > 0 && op < 16)
	{
		g_fct_ptr[0] = ft_live;
		g_fct_ptr[1] = ft_ld;
		g_fct_ptr[2] = ft_st;
		g_fct_ptr[3] = ft_add;
		g_fct_ptr[4] = ft_sub;
		g_fct_ptr[5] = ft_and;
		g_fct_ptr[6] = ft_or;
		g_fct_ptr[7] = ft_xor;
		g_fct_ptr[8] = ft_zjmp;
		g_fct_ptr[9] = ft_ldi;
		g_fct_ptr[10] = ft_sti;
		g_fct_ptr[11] = ft_fork;
		g_fct_ptr[12] = ft_lld;
		g_fct_ptr[13] = ft_lldi;
		g_fct_ptr[14] = ft_lfork;
		g_fct_ptr[15] = ft_aff;
		(*g_fct_ptr[op - 1])(args, vm, process);
	}
	process->is_waiting = 0;
}

static int	get_next_pc(t_vm *vm, t_process *process, int op)
{
	int		cursor;

	cursor = process->pc;
	if (op == LIVE)
		cursor += 4;
	else if (op == FORK || op == LFORK)
		cursor += 2;
	else if (op > 0 && op < 17)
		cursor = handle_coding_byte(cursor, vm, op);
	cursor++;
	cursor = ft_loop_memory(cursor);
	return (cursor);
}

static int	get_cycles_to_wait(int op, t_process *process)
{
	int		cycles_to_wait[16];

	cycles_to_wait[0] = 10;
	cycles_to_wait[1] = 5;
	cycles_to_wait[2] = 5;
	cycles_to_wait[3] = 10;
	cycles_to_wait[4] = 10;
	cycles_to_wait[5] = 6;
	cycles_to_wait[6] = 6;
	cycles_to_wait[7] = 6;
	cycles_to_wait[8] = 20;
	cycles_to_wait[9] = 25;
	cycles_to_wait[10] = 25;
	cycles_to_wait[11] = 800;
	cycles_to_wait[12] = 10;
	cycles_to_wait[13] = 50;
	cycles_to_wait[14] = 1000;
	cycles_to_wait[15] = 2;
	if ((process->waiting_op = op) > 0 && op < 16)
	{
		process->is_waiting = 1;
		return (cycles_to_wait[op - 1]);
	}
	process->is_waiting = 0;
	return (1);
}

static void	proceed_cycles(t_vm *vm)
{
	t_process	*process;
	int			op;
	int			next_pc;

	process = vm->process;
	while (process)
	{
		op = vm->memory[process->pc];
		next_pc = get_next_pc(vm, process, op);
		if (!process->is_waiting)
			process->cycles_to_wait = get_cycles_to_wait(op, process);
		if (process->waiting_op != op)
		{
			process->cycles_to_wait = get_cycles_to_wait(op, process);
			process = process->next;
			continue ;
		}
		if (process->cycles_to_wait == 1)
			exec_action(vm, process, op);
		else
			process->cycles_to_wait--;
		if (op != ZJMP && !process->is_waiting)
			process->pc = next_pc;
		process = process->next;
	}
}

void		start_running_vm(t_vm *vm)
{
	int		cycle;

	cycle = 1;
	while (42)
	{
		if (vm->cycle_in_current_period == vm->cycle_to_die)
			ft_check_alive(vm);
		proceed_cycles(vm);
		if (cycle == vm->dump_cycle)
		{
			hexdump(vm->memory, MEM_SIZE);
			exit(0);
		}
		if (vm->cycle_to_die < 0)
			ft_finish(vm);
		vm->cycle_in_current_period++;
		cycle++;
	}
}
