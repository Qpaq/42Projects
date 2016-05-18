/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:41:53 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:55 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_label_size(int op)
{
	if (op == LIVE || op == LD || op == AND || op == OR || op == XOR)
		return (4);
	else if (op == ST || op == ADD || op == SUB || op == AFF)
		return (0);
	else
		return (2);
}

int		get_argument_type(char *bin)
{
	if (ft_strncmp(bin, "10", 2) == 0)
		return (T_DIR);
	else if (ft_strncmp(bin, "11", 2) == 0)
		return (T_IND);
	else if (ft_strncmp(bin, "01", 2) == 0)
		return (T_REG);
	return (0);
}

void	get_op_args_values(t_vm *vm, t_process *process, int op, t_arg *args)
{
	int i;
	int cursor;

	i = -1;
	cursor = (op == LIVE || op == ZJMP || op == FORK || op == LFORK) ? 1 : 2;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (args->types[i] == T_REG)
		{
			args->values[i] =
			vm->memory[ft_loop_memory((process->pc + cursor))];
			cursor++;
		}
		else if (args->types[i] == T_IND || (args->types[i] == T_DIR &&
											get_label_size(op) == 2))
		{
			args->values[i] = get_int_from_two_bytes(vm, process, cursor);
			cursor = cursor + 2;
		}
		else if (args->types[i] == T_DIR && get_label_size(op) == 4)
		{
			args->values[i] = get_int_from_bytes(vm, process, cursor);
			cursor = cursor + 4;
		}
	}
}

void	get_op_args_types(t_vm *vm, t_process *process, int op, t_arg *args)
{
	char	*coding_byte;
	int		i;

	if (op == LIVE || op == ZJMP || op == FORK || op == LFORK)
		args->types[0] = T_DIR;
	else
	{
		coding_byte =
		ft_itoa_base(vm->memory[ft_loop_memory((process->pc + 1))], 2, 0);
		if (ft_strlen(coding_byte) < 8)
			coding_byte = ft_strjoin("0", coding_byte);
		i = 0;
		while (i < 6)
		{
			if (get_argument_type(coding_byte + i) == T_REG)
				args->types[i / 2] = T_REG;
			else if (get_argument_type(coding_byte + i) == T_IND)
				args->types[i / 2] = T_IND;
			else if (get_argument_type(coding_byte + i) == T_DIR)
				args->types[i / 2] = T_DIR;
			else
				args->types[i / 2] = 0;
			i = i + 2;
		}
	}
}

t_arg	*get_op_args(t_vm *vm, t_process *process, int op)
{
	t_arg	*args;
	int		args_count;

	if (!(args = (t_arg *)ft_memalloc(sizeof(t_arg))))
		ft_error("Error : malloc t_arg");
	get_op_args_types(vm, process, op, args);
	get_op_args_values(vm, process, op, args);
	args_count = 0;
	while (args_count < MAX_ARGS_NUMBER)
	{
		if (args->types[args_count] == 0)
			break ;
		args_count++;
	}
	args->count = args_count;
	return (args);
}
