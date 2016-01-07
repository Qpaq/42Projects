/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 14:03:50 by alhote            #+#    #+#             */
/*   Updated: 2015/08/23 23:19:26 by ssivagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle.h"

int		check_line(t_rectangle_spec *colle, char *rectangle, int *position)
{
	if (colle->size_x > 1)
	{
		if ((position[0] > 1 && position[0] < colle->size_x)
				&& position[1] == 1)
		{
			if (rectangle[position[2]] == colle->ch)
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
		if (position[0] == colle->size_x && position[1] == 1)
		{
			if (rectangle[position[2]] == colle->hd)
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
	}
	return (1);
}

int		check_column(t_rectangle_spec *colle, char *rectangle, int *position)
{
	if (colle->size_y > 1)
	{
		if (position[0] == 1 && (position[1] > 1
					&& position[1] < colle->size_y))
		{
			if (rectangle[position[2]] == colle->cc)
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
		if (position[0] == 1 && position[1] == colle->size_y)
		{
			if (rectangle[position[2]] == colle->bg)
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
	}
	return (1);
}

int		check_bloc(t_rectangle_spec *colle, char *rectangle, int *position)
{
	if (colle->size_x > 1 && colle->size_y > 1)
	{
		if (position[0] == colle->size_x && position[1] == colle->size_y)
		{
			if (rectangle[position[2]] == colle->bd)
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
		if (position[0] > 1 && position[0] < colle->size_x &&
				position[1] > 1 && position[1] < colle->size_y)
		{
			if (rectangle[position[2]] == ' ')
				colle->colle = 1;
			else
				return (colle->colle = 0);
		}
	}
	return (1);
}

int		check(t_rectangle_spec *colle, char *rectangle, int *position)
{
	if (!check_line(colle, rectangle, position))
		return (0);
	if (!check_column(colle, rectangle, position))
		return (0);
	if (!check_bloc(colle, rectangle, position))
		return (0);
	return (1);
}

int		try_parse(t_rectangle_spec *colle, char *rectangle)
{
	int		position[3];

	position[0] = 0;
	position[1] = 1;
	position[2] = -1;
	while (position[1] <= colle->size_y)
	{
		if (rectangle[position[2]] == '\n')
		{
			position[2]++;
			position[1]++;
			position[0] = 1;
		}
		if (position[0] == 1 && position[1] == 1)
		{
			colle->colle = rectangle[position[2]] == colle->hg ? 1 : 0;
			if (colle->colle == 0)
				return (0);
		}
		if (!check(colle, rectangle, position))
			return (0);
		position[2]++;
		position[0]++;
	}
	return (0);
}
