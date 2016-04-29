/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:47:44 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 10:57:04 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		go_to(char *from, char *to, t_ant *ant, t_rooms *rooms)
{
	t_rooms		*room_to;
	t_rooms		*room_from;

	if (ft_strcmp(from, to) != 0)
	{
		ant->current_room = ft_strdup(to);
		room_from = get_room_from_name(from, rooms);
		room_to = get_room_from_name(to, rooms);
		room_from->busy = 0;
		room_to->busy = 1;
		if (room_to->is_end)
		{
			ant->arrived = 1;
			room_to->busy = 0;
		}
		ft_printf("L%d-%s ", ant->num, to);
	}
}

void		proceed_steps(t_rooms *rooms, t_ant *ant)
{
	t_ant	*first_ant;
	char	*room_to_go;

	first_ant = ant;
	while (!all_arrived(first_ant))
	{
		while (ant)
		{
			if (ant->arrived)
			{
				ant = ant->next;
				continue ;
			}
			room_to_go = get_best_room(rooms, ant->current_room);
			if (get_room_from_name(room_to_go, rooms)->busy)
				room_to_go = check_other_rooms(rooms, ant->current_room,
						get_room_from_name(room_to_go, rooms)->weight);
			go_to(ant->current_room, room_to_go, ant, rooms);
			ant = ant->next;
		}
		ft_printf("\n");
		ant = first_ant;
	}
}

t_ant		*append_ant(t_ant *head, int num, char *start_room)
{
	t_ant	*new;
	t_ant	*tmp;

	tmp = head;
	new = (t_ant *)ft_memalloc(sizeof(t_ant));
	new->num = num;
	new->arrived = 0;
	new->current_room = ft_strdup(start_room);
	new->next = NULL;
	if (head == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}

t_ant		*create_ants(int count, char *start_room)
{
	t_ant	*ants;
	int		i;

	i = 1;
	ants = NULL;
	while (i <= count)
	{
		ants = append_ant(ants, i, start_room);
		i++;
	}
	return (ants);
}

void		all_engine_running(t_rooms *rooms, int nb_ants)
{
	t_ant	*ants;
	char	*start_room;

	start_room = get_start_room_name(rooms);
	ants = create_ants(nb_ants, start_room);
	proceed_steps(rooms, ants);
}
