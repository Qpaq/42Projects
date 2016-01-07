/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 17:35:44 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 19:00:13 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*begin_list;
	t_list	*new;

	new = ft_create_elem(av[1]);
	begin_list = new;
	i = 2;
	while (i < ac)
	{
		new = ft_create_elem(av[i]);
		new->next = begin_list;
		begin_list = new;
		i++;
	}
	return (begin_list);
}
