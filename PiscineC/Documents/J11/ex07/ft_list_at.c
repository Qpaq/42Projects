/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 19:19:34 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 20:17:32 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*elem;
	int		index;

	index = 1;
	elem = begin_list;
	while (elem->next)
	{
		if (index == nbr)
			return (elem);
		elem = elem->next;
		index++;
	}
	return (NULL);
}
