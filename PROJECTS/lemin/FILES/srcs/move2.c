/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:50:01 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 10:59:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_room_state(t_rooms *rooms)
{
	ft_printf("\n------ROOM STATE---------\n");
	while (rooms)
	{
		ft_printf("[name= {%s} busy {%d}\n", rooms->name, rooms->busy);
		rooms = rooms->next;
	}
	ft_printf("------------------------\n");
}

char	*get_start_room_name(t_rooms *rooms)
{
	while (rooms)
	{
		if (rooms->is_start)
			return (rooms->name);
		rooms = rooms->next;
	}
	return (NULL);
}

char	*check_other_rooms(t_rooms *rooms, char *current_name, int best_weight)
{
	t_rooms		*current;
	t_rooms		*tmp;
	int			i;

	i = 0;
	current = get_room_from_name(current_name, rooms);
	while (current->connections[i])
	{
		tmp = get_room_from_name(current->connections[i], rooms);
		if (!tmp->busy && tmp->weight < best_weight + 1)
		{
			return (tmp->name);
		}
		i++;
	}
	return (current->name);
}

int		all_arrived(t_ant *ant)
{
	while (ant)
	{
		if (ant->arrived == 0)
			return (0);
		ant = ant->next;
	}
	return (1);
}
