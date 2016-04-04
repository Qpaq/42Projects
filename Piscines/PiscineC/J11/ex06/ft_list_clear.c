/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 19:01:32 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 19:17:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*elem;
	t_list	*to_destroy;

	elem = *begin_list;
	while (elem->next)
	{
		to_destroy = elem;
		elem = elem->next;
		free(to_destroy);
	}
}
