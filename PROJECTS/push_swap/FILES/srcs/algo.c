/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:43:23 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/22 09:42:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_pile_reverse(int *pile, int length)
{
	int		i;

	i = 1;
	while (i < length)
	{
		if (pile[i - 1] > pile[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_pile(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
	if (check_pile_reverse(pile, length))
		return (-1);
	i = 1;
	while (i < length)
	{
		if (pile[i - 1] < pile[i])
			return (0);
		i++;
	}
	return (1);
}

void	put_smallest_last(t_pushswap *data)
{
	int		i;

	i = 0;
	while (i < length)
	{
	}
}

int		sort_pile(t_pushswap *data)
{
	int		state;

	while (42)
	{
		put_smallest_last(data);
		if ((state = check_pile(data->pile_a, data->length_a)))
			break ;
	}
	if (state == -1)
		reverse_pile(data->pile_a, data->length_a);
	return (1);
}
