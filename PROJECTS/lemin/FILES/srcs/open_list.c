/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:59:18 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 19:39:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_open			*init_open(t_rooms *end)
{
	t_open		*open_list;

	if (!(open_list = (t_open*)malloc(sizeof(t_open))))
		return (NULL);
	open_list->room = end;
	open_list->next = NULL;
	open_list->prev = NULL;
	return (open_list);
}

t_open			*add_to_open(t_open *open_list, t_rooms *room)
{
	t_open		*new_open;
	t_open		*tmp;

	if (!open_list->room)
		open_list = init_open(room);
	else
	{
		new_open = init_open(room);
		tmp = open_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_open;
		new_open->prev = tmp;
	}
	return (open_list);
}

t_open			*remove_from_open(t_open *open_list, t_rooms *room)
{
	t_open		*tmp;

	tmp = open_list;
	while (tmp)
	{
		if (tmp->room == room)
		{
			tmp->room = NULL;
			if (tmp->next && tmp->prev)
			{
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
			}
			else if (tmp->next && !(tmp->prev))
			{
				tmp->next->prev = NULL;
				open_list = tmp->next;
			}
			else if (tmp->prev && !tmp->next)
				tmp->prev->next = NULL;
			return (open_list);
		}
		tmp = tmp->next;
	}
	return (open_list);
}

int				is_in_open(t_open *open_list, t_rooms *connection)
{
	t_open		*tmp;

	tmp = open_list;
	while (tmp)
	{
		if (tmp->room == connection)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
