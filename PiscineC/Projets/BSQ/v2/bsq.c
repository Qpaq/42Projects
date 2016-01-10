/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 13:23:01 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 16:36:39 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		init_previous_line(int *previous, t_grid_specs *specs)
{
	int i;

	i = 0;
	while (i <= specs->columns)
	{
		previous[i] = 0;
		i++;
	}
}

t_max		*bsq(char **grid, t_grid_specs *specs)
{
	int		i;
	int		j;
	int		around[3];
	int		min;
	int		*previous_line;
	int		*current_line;
	t_max	*max;

	max = (t_max*)malloc(sizeof(t_max));
	max->value = 1;
	
	previous_line = (int*)malloc(sizeof(int) * (specs->columns + 2));
	init_previous_line(previous_line, specs);
	current_line = (int*)malloc(sizeof(int) * (specs->columns + 2));
	
	i = 1;
	while (i <= specs->lines)
	{
		j = 1;
		while (j <= specs->columns)
		{
			if (j == 1)
				current_line[j - 1] = 0;
			if (grid[i - 1][j - 1] == specs->obstacle)
				current_line[j] = 0;
			
			if ((i != 1) && (j != 1) && grid[i - 1][j - 1] != specs->obstacle)
			{
				around[0] = previous_line[j];
				around[1] = previous_line[j - 1];
				around[2] = current_line[j - 1];
				min = ft_min(around);
				current_line[j] = min + 1;
				if (current_line[j] > max->value)
				{
					max->value = current_line[j];
					max->line = i - 1;
					max->col = j - 1;
				}
			}
			j++;
		}
		previous_line = current_line;
		i++;
	}
	return (max);
}

void final_grid(char **grid, t_grid_specs *specs)
{
	t_max	*max;
	int		i;
	int		j;
	int		idebut;
	int		jdebut;

	i = 0;
	j = 0;
	max = bsq(grid, specs);
	idebut = max->line - (max->value - 1);
	jdebut = max->col - (max->value - 1);
	while (i < max->value)
	{
		j = 0;
		while (j < max->value)
		{
			grid[i + idebut][j + jdebut] = specs->filled;
			j++;
		}
		i++;
	}
	free(max);
}
