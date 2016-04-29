/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:41:32 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 18:32:01 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms		*get_current(t_open *open_list)
{
	t_open		*tmp;
	t_rooms		*current;

	tmp = open_list;
	current = open_list->room;
	while (tmp)
	{
		if (tmp->room->weight < current->weight)
			current = tmp->room;
		tmp = tmp->next;
	}
	return (current);
}

void		algo_path(t_rooms *start, t_open *open_list, t_close *close_list)
{
	t_rooms		*current;
	int			weight;
	t_rooms		*connection;
	int			i;

	weight = 1;
	while (open_list->room)
	{
		i = 0;
		current = get_current(open_list);
		close_list = add_to_close(close_list, current);
		open_list = remove_from_open(open_list, current);
		while (current->nb_of_connections && current->connections[i] &&
			(connection = get_room_from_name(current->connections[i], start)))
		{
			if (is_in_close(close_list, connection) && (i = i + 1))
				continue ;
			if (!(is_in_open(open_list, connection)))
				open_list = add_to_open(open_list, connection);
			if (weight < connection->weight)
				connection->weight = weight;
			i++;
		}
		weight++;
	}
}

int			get_path(t_rooms *end, t_rooms *start)
{
	t_open		*open_list;
	t_close		*close_list;

	open_list = init_open(end);
	close_list = NULL;
	algo_path(start, open_list, close_list);
	if (start->weight == INT_MAX)
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	return (1);
}
