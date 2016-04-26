/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:08:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 17:08:32 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_pile(int *pile, int length)
{
	int		i;

	if (length == 1)
		return (1);
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
	if (data->pos_smallest_a < data->length_a / 2)
	{
		while (data->pos_smallest_a != data->length_a - 1)
		{
			rotate_a(data);
			data->nb_of_moves++;
		}
	}
	else
	{
		while (data->pos_smallest_a != data->length_a - 1)
		{
			reverse_rotate_a(data);
			data->nb_of_moves++;
		}
	}
}

void	sort_pile(t_pushswap *data)
{
	while (42)
	{
		put_smallest_last(data);
		if (check_pile(data->pile_a, data->length_a))
		{
			if (data->length_b == 0)
				break ;
			else
			{
				while (data->length_b > 0)
				{
					push_a(data);
					data->nb_of_moves++;
				}
			}
		}
		else
		{
			push_b(data);
			data->nb_of_moves++;
		}
	}
}
