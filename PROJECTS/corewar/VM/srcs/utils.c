/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:41:23 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:27 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_byte(long value, t_vm *vm, long number, t_process *process)
{
	int		byte;
	long	mult;
	int		i;

	i = 0;
	mult = 256L * 256L * 256L;
	if (value < 0)
		value = mult * 256L + value;
	while (i < 4)
	{
		byte = value / mult;
		vm->memory[ft_loop_memory(process->pc + number + i)] = byte;
		value -= byte * mult;
		mult /= 256L;
		i++;
	}
}

long	get_value_depending_on_type(int pos, t_arg *args,
									t_process *process, t_vm *vm)
{
	long	value;

	value = 0;
	if (args->types[pos] == T_REG)
		value = process->reg[args->values[pos] - 1];
	else if (args->types[pos] == T_IND)
		value = vm->memory[ft_loop_memory((process->pc +
										(args->values[pos] % IDX_MOD)))];
	else if (args->types[pos] == T_DIR)
		value = args->values[pos];
	process->carry = 1;
	return (value);
}

int		ft_check_reg_exist(t_arg *args)
{
	int	i;

	i = 0;
	while (i < args->count)
	{
		if (args->types[i] == T_REG)
		{
			if (args->values[i] < 1 || args->values[i] > REG_NUMBER)
				return (0);
		}
		i++;
	}
	return (1);
}

int		handle_coding_byte(int cursor, t_vm *vm, int op)
{
	int		i;
	char	*coding_byte;

	cursor += 1;
	coding_byte = ft_itoa_base(vm->memory[ft_loop_memory(cursor)], 2, 0);
	if (ft_strlen(coding_byte) < 8)
		coding_byte = ft_strjoin("0", coding_byte);
	i = 0;
	while (i < 6)
	{
		if (get_argument_type(coding_byte + i) == T_REG)
			cursor += 1;
		if (get_argument_type(coding_byte + i) == T_IND)
			cursor += 2;
		if (get_argument_type(coding_byte + i) == T_DIR)
			cursor += get_label_size(op);
		i = i + 2;
	}
	return (cursor);
}

int		ft_loop_memory(int value)
{
	int		ret;

	ret = value;
	while (ret < 0)
		ret = MEM_SIZE + ret;
	if (ret >= MEM_SIZE)
		ret = value % MEM_SIZE;
	return (ret);
}
