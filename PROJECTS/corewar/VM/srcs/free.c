/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:39:23 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:39:25 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_first(t_vm *vm, t_process **tmp)
{
	vm->process = (*tmp)->next;
	free(*tmp);
	*tmp = NULL;
	if (!vm->process)
		ft_finish(vm);
	*tmp = vm->process;
	(*tmp)->prev = NULL;
}

void		free_middle(t_process **tmp)
{
	t_process	*to_free;

	(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->next->prev = (*tmp)->prev;
	to_free = *tmp;
	*tmp = (*tmp)->next;
	free(to_free);
	to_free = NULL;
}

void		free_last(t_process **tmp)
{
	(*tmp)->prev->next = NULL;
	free(*tmp);
	*tmp = NULL;
}
