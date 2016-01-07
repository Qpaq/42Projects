/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 19:01:57 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 19:24:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*temp;

	elem2 = lst;
	if (elem2 == NULL)
		return (NULL);
	elem1 = elem2->next;
	while (elem1->next)
	{
		if (cmp(elem2->data, elem1->data) == 0)
		{
			temp = elem1->next;
			elem2->next = elem1->next;
			elem1->next = elem2;
		}
		elem1 = elem1->next;
	}
	return (lst);
}
