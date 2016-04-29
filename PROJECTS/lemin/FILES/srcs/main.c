/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:37:19 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 19:40:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_rooms(t_rooms *rooms)
{
	int		i;

	while (rooms)
	{
		i = 0;
		ft_printf("NAME= %s [start? %d, end? %d] (x:%d, y:%d)\n",
				rooms->name, rooms->is_start, rooms->is_end,
				rooms->pos_x, rooms->pos_y);
		ft_printf("-->Nb connections: %d; Weight: %d\n--> Connections=",
				rooms->nb_of_connections, rooms->weight);
		if (rooms->connections)
		{
			while (rooms->connections[i])
			{
				ft_printf(" %s", rooms->connections[i]);
				i++;
			}
		}
		else
			ft_putendl("No connections");
		rooms = rooms->next;
		ft_putendl("\n-----\n");
	}
	return (1);
}

t_rooms	*get_end_room(t_rooms *rooms)
{
	t_rooms	*end;
	int		begin;

	end = NULL;
	begin = 0;
	while (rooms)
	{
		if (rooms->is_start)
			begin = 1;
		if (rooms->is_end == 1)
		{
			rooms->weight = 0;
			end = rooms;
		}
		rooms = rooms->next;
	}
	if (begin && end)
		return (end);
	return (NULL);
}

t_rooms	*get_start_room(t_rooms *rooms)
{
	t_rooms	*start;
	t_rooms	*tmp;
	t_rooms	*previous;

	start = NULL;
	tmp = rooms;
	previous = rooms;
	if (rooms->is_start)
		return (rooms);
	while (rooms)
	{
		if (rooms->is_start)
		{
			start = rooms;
			previous->next = start->next;
			start->next = tmp;
			break ;
		}
		previous = rooms;
		rooms = rooms->next;
	}
	return (start);
}

int		check_number_of_ants(char *line)
{
	int		i;
	int		res;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '+')
			return (-1);
		i++;
	}
	if (ft_strlen(line) == 1 && line[0] == '+')
		return (-1);
	if (ft_strlen(line) >= 10 && ft_strcmp(line, ft_itoa(INT_MAX)) > 0)
		return (-1);
	res = ft_atoi(line);
	if (res <= 0)
		return (-1);
	return (res);
}

int		main(void)
{
	t_rooms		*rooms;
	int			nb_ants;
	char		*file;
	t_rooms		*end_room;

	rooms = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	get_next_line(0, &file);
	if ((nb_ants = check_number_of_ants(file)) == -1)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	file = ft_strjoin(file, "\n");
	parse_file(&rooms, 0, 0, &file);
	if ((end_room = get_end_room(rooms)) == NULL)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	rooms = get_start_room(rooms);
	get_path(end_room, rooms);
	ft_putendl(file);
	all_engine_running(rooms, nb_ants);
	return (0);
}
