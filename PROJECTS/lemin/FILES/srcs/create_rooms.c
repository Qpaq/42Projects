/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 10:04:13 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 19:50:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_coord(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '+')
		line++;
	while (line[i] != '\0')
	{
		if (line[i] == '.' || !ft_isdigit(line[i]))
			return (0);
		i++;
	}
	if (ft_strlen(line) >= 10 && ft_strcmp(line, ft_itoa(INT_MAX)) > 0)
		return (0);
	return (1);
}

int			add_con(t_rooms *rooms, char **line, int ret)
{
	char	**tmp;

	while (rooms)
	{
		if (ft_strcmp(rooms->name, line[0]) == 0
				|| ft_strcmp(rooms->name, line[1]) == 0)
		{
			rooms->nb_of_connections++;
			tmp = (char **)ft_memalloc(sizeof(char *) *
					(rooms->nb_of_connections + 1));
			if (rooms->connections != NULL)
				ft_memcpy(tmp, rooms->connections, sizeof(char *) *
						rooms->nb_of_connections);
			if (ft_strcmp(rooms->name, line[0]) == 0)
				tmp[rooms->nb_of_connections - 1] = ft_strdup(line[1]);
			else if (ft_strcmp(rooms->name, line[1]) == 0)
				tmp[rooms->nb_of_connections - 1] = ft_strdup(line[0]);
			tmp[rooms->nb_of_connections] = NULL;
			rooms->connections = tmp;
			ret++;
		}
		rooms = rooms->next;
	}
	return (ret);
}

t_rooms		*add_room(t_rooms *head, char **line, int start, int end)
{
	t_rooms	*new;
	t_rooms	*node;

	if (line[0][0] == 'L')
		return (NULL);
	node = head;
	new = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	new->name = ft_strdup(line[0]);
	if (!check_coord(line[1]) || !check_coord(line[2]))
		return (NULL);
	if ((new->pos_x = ft_atoi(line[1])) < 0)
		return (NULL);
	if ((new->pos_y = ft_atoi(line[2])) < 0)
		return (NULL);
	new->weight = INT_MAX;
	if (start)
		new->is_start = 1;
	if (end)
		new->is_end = 1;
	while (node->next)
		node = node->next;
	node->next = new;
	if (head->name == NULL)
		return (new);
	return (head);
}
