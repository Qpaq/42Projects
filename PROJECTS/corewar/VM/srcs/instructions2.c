/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:40:32 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:40:33 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_and(t_arg *args, t_vm *vm, t_process *process)
{
	long	value1;
	long	value2;

	if ((args->types[0] != T_DIR && args->types[0] != T_IND &&
									args->types[0] != T_REG) ||
		(args->types[1] != T_DIR && args->types[1] != T_IND &&
									args->types[1] != T_REG) ||
		args->types[2] != T_REG)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (int)(value1 & value2);
		if (process->reg[args->values[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}

void		ft_or(t_arg *args, t_vm *vm, t_process *process)
{
	long	value1;
	long	value2;

	if ((args->types[0] != T_DIR && args->types[0] != T_IND &&
									args->types[0] != T_REG) ||
		(args->types[1] != T_DIR && args->types[1] != T_IND &&
									args->types[1] != T_REG) ||
		args->types[2] != T_REG)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (int)(value1 | value2);
		if (process->reg[args->values[2] - 1] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}

void		ft_xor(t_arg *args, t_vm *vm, t_process *process)
{
	long	value1;
	long	value2;

	if ((args->types[0] != T_DIR && args->types[0] != T_IND &&
									args->types[0] != T_REG) ||
		(args->types[1] != T_DIR && args->types[1] != T_IND &&
									args->types[1] != T_REG) ||
		args->types[2] != T_REG)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		value1 = get_value_depending_on_type(0, args, process, vm);
		value2 = get_value_depending_on_type(1, args, process, vm);
		process->reg[args->values[2] - 1] = (int)(value1 ^ value2);
		if (process->reg[args->values[2] - 1])
			process->carry = 0;
		else
			process->carry = 1;
	}
	else
		process->carry = 0;
}

void		ft_zjmp(t_arg *args, t_vm *vm, t_process *process)
{
	if (process->carry == 1)
		process->pc = ft_loop_memory(process->pc +
									(args->values[0] % IDX_MOD));
	else
		process->pc = (process->pc + 3) % MEM_SIZE;
	(void)vm;
}

void		ft_ldi(t_arg *args, t_vm *vm, t_process *process)
{
	long	values[2];
	long	addr;
	int		value;

	if ((args->types[0] != T_DIR && args->types[0] != T_IND &&
		args->types[0] != T_REG) || (args->types[1] != T_DIR &&
		args->types[1] != T_REG) || args->types[2] != T_REG)
	{
		process->carry = 0;
		return ;
	}
	if (ft_check_reg_exist(args))
	{
		values[0] = get_value_depending_on_type(0, args, process, vm);
		values[1] = get_value_depending_on_type(1, args, process, vm);
		addr = values[0] + values[1];
		value = get_int_from_bytes(vm, process, addr % IDX_MOD);
		process->reg[args->values[2] - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
}
