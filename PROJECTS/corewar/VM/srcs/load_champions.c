/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:41:08 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:10 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*add_process(t_process *process, int pc,
							int number_champ, int number)
{
	t_process	*new;

	if (!(new = (t_process *)ft_memalloc(sizeof(t_process))))
		ft_error("Error : malloc process");
	new->carry = 0;
	new->live = 0;
	new->cycles_to_wait = 0;
	new->is_waiting = 0;
	new->waiting_op = 0;
	new->pc = pc;
	new->reg[0] = number_champ;
	new->num = number;
	new->next = NULL;
	if (!process)
	{
		new->prev = NULL;
		return (new);
	}
	process->prev = new;
	new->next = process;
	return (new);
}

void		load_champions(t_vm *vm)
{
	t_process	*process;
	int			offset;
	int			i;

	i = 0;
	offset = MEM_SIZE / vm->champ_nb;
	process = NULL;
	while (i < vm->champ_nb)
	{
		process = add_process(process, offset * i, vm->champions[i].number, i);
		ft_memcpy(vm->memory + offset * i,
			vm->champions[i].data, vm->champions[i].data_len);
		i++;
	}
	vm->process = process;
	vm->nb_process = vm->champ_nb;
}
