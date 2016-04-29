/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:04:09 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 10:38:48 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms	*get_room_from_name(char *room, t_rooms *rooms)
{
	t_rooms *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strcmp(room, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		get_room_weight(char *room, t_rooms *rooms)
{
	while (rooms)
	{
		if (ft_strcmp(room, rooms->name) == 0)
			return (rooms->weight);
		rooms = rooms->next;
	}
	return (-1);
}

char	*get_best_room(t_rooms *rooms, char *current)
{
	int		i;
	int		min;
	t_rooms	*room;
	char	*res;
	t_rooms	*tmp;

	room = get_room_from_name(current, rooms);
	if (room == NULL || room->nb_of_connections == 0)
		return (NULL);
	i = 0;
	min = INT_MAX;
	res = NULL;
	while (room->connections[i])
	{
		tmp = get_room_from_name(room->connections[i], rooms);
		if (tmp->weight < min)
		{
			min = tmp->weight;
			res = ft_strdup(tmp->name);
		}
		i++;
	}
	return (res);
}
