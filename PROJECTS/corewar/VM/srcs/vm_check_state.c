/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:41:45 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:41:47 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_finish(t_vm *vm)
{
	int		i;

	i = 0;
	if (vm->champ_nb < 2)
		ft_printf("Le joueur %d (%s) a gagne\n",
		vm->last_champion_alive_number, vm->last_champion_alive_name);
	else
	{
		while (i < vm->champ_nb)
		{
			if (vm->champions[i].number == vm->last_champion_alive_number)
				ft_printf("Le joueur %d (%s) a gagne\n",
				vm->champions[i].number, vm->champions[i].name);
			i++;
		}
	}
	exit(0);
}

static void		ft_check_process(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->process;
	if (!tmp)
		ft_finish(vm);
	while (tmp)
	{
		if (tmp->live == 0)
		{
			if (tmp->prev == NULL)
				free_first(vm, &tmp);
			else if (tmp->next == NULL)
			{
				free_last(&tmp);
				return ;
			}
			else
				free_middle(&tmp);
		}
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
		}
	}
}

void			ft_check_alive(t_vm *vm)
{
	int			i;
	static int	checks_without_decrementing = 0;

	i = 0;
	checks_without_decrementing++;
	ft_check_process(vm);
	if (vm->lives_in_current_period >= NBR_LIVE ||
		checks_without_decrementing >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_without_decrementing = 0;
	}
	vm->lives_in_current_period = 0;
	vm->cycle_in_current_period = 0;
	if (vm->process == NULL)
		ft_finish(vm);
}
