/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 13:23:01 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 17:26:23 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_max		*get_square(int **grid_num, t_grid_specs *specs)
{
	t_max	*max;
	int		i;
	int		j;

	max = (t_max*)malloc(sizeof(t_max));
	max->value = 1;
	i = 0;
	max->line = 0;
	max->col = 0;
	while (i < specs->lines)
	{
		j = 0;
		while (j < specs->columns)
		{
			if (grid_num[i][j] > max->value)
			{
				max->value = grid_num[i][j];
				max->line = i;
				max->col = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

t_max		*bsq(int **grid_num, t_grid_specs *specs)
{
	int		i;
	int		j;
	int		around[3];
	int		min;
	t_max	*max;

	i = 1;
	min = 0;
	while (i < specs->lines)
	{
		j = 1;
		while (j < specs->columns)
		{
			if (grid_num[i][j] != 0)
			{
				around[0] = grid_num[i - 1][j];
				around[1] = grid_num[i][j - 1];
				around[2] = grid_num[i - 1][j - 1];
				min = ft_min(around, 3);
				grid_num[i][j] = min + 1;
			}
			j++;
		}
		i++;
	}
	max = get_square(grid_num, specs);
	free_tab_num(grid_num, specs);
	return (max);
}

char		**final_grid(char **grid, t_grid_specs *specs, int **grid_num)
{
	t_max	*max;
	int		i;
	int		j;
	int		idebut;
	int		jdebut;

	i = 0;
	j = 0;
	max = bsq(grid_num, specs);
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
	return (grid);
}

int			**init_grid_num(char **grid, t_grid_specs *specs)
{
	int		**grid_num;
	int		i;
	int		j;

	i = 0;
	grid_num = (int**)malloc(sizeof(int*) * specs->lines);
	while (i < specs->lines)
	{
		j = 0;
		grid_num[i] = (int*)malloc(sizeof(int) * specs->columns);
		while (j < specs->columns)
		{
			if (i == 0)
				grid_num[i][j] = 1;
			if (j == 0)
				grid_num[i][j] = 1;
			if (grid[i][j] == specs->obstacle)
				grid_num[i][j] = 0;
			if ((i != 0) && (j != 0) && grid[i][j] != specs->obstacle)
				grid_num[i][j] = 2;
			j++;
		}
		i++;
	}
	return (grid_num);
}
