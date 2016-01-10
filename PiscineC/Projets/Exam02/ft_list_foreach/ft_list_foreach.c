/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 19:26:55 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 19:39:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*elem;

	elem = begin_list;
	if (elem != (void*)0)
	{
		while (elem->next)
		{
			f(elem->data);
			elem = elem->next;
		}
	}
}
