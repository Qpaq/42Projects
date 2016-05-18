/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:40:55 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:01 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_fork(t_arg *args, t_vm *vm, t_process *process)
{
	t_process	*new;
	int			i;

	if (!(new = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_error("Error : malloc process");
	new->live = process->live;
	new->carry = process->carry;
	new->cycles_to_wait = 0;
	new->waiting_op = 0;
	new->pc = ft_loop_memory((process->pc + (args->values[0] % IDX_MOD)));
	new->num = vm->nb_process;
	new->prev = NULL;
	process->is_waiting = 0;
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = process->reg[i];
		i++;
	}
	vm->process->prev = new;
	new->next = vm->process;
	vm->process = new;
	vm->nb_process++;
}

void		ft_lfork(t_arg *args, t_vm *vm, t_process *process)
{
	t_process	*new;
	int			i;

	if (!(new = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_error("Error : malloc process");
	new->live = process->live;
	new->carry = process->carry;
	new->waiting_op = 0;
	new->cycles_to_wait = 0;
	new->pc = ft_loop_memory(process->pc + args->values[0]);
	new->num = vm->nb_process;
	new->prev = NULL;
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = process->reg[i];
		i++;
	}
	vm->process->prev = new;
	new->next = vm->process;
	vm->process = new;
	vm->nb_process++;
}

void		ft_aff(t_arg *args, t_vm *vm, t_process *process)
{
	if (args->values[0] > 0 && args->values[0] <= REG_NUMBER)
		ft_putchar((unsigned char)process->reg[args->values[0]]);
	(void)args;
	(void)vm;
}
