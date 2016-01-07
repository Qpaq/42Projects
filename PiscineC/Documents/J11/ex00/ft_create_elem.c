/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 10:08:16 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 18:29:16 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	if (NULL != (new = (t_list*)malloc(sizeof(t_list))))
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}
