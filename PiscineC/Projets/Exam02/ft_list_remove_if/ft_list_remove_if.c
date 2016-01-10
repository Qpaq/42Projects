/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 18:31:55 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 18:59:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*elem;
	t_list	*previous;
	t_list	*destroy;

	elem = *begin_list;
	previous = *begin_list;
	if (elem != NULL)
	{
		if (elem->next == NULL && cmp(elem->data, data_ref))
			free(elem);
		while (elem->next)
		{
			destroy = elem;
			elem = elem->next;
			if (cmp(destroy->data, data_ref))
			{
				previous->next = elem;
				free(destroy);
			}
			else
				previous = previous->next;
		}
	}
}
