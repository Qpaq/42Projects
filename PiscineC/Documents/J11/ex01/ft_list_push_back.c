/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 10:43:49 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 18:37:09 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp;
	t_list	*new;

	new = ft_create_elem(data);
	temp = *begin_list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
