/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 17:28:32 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 19:51:19 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*temp;

	count = 1;
	temp = begin_list;
	if (temp == NULL)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
