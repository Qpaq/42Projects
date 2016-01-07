/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 17:29:51 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 12:28:07 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				check_first_line(char *grid, t_grid_specs *grid_specs)
{
	int		i;
	char	*nb;
	int		size_nb;

	i = 0;
	nb = NULL;
	size_nb = 1;
	while (grid[i] != '\n')
	{
		if (grid[0] < 48 || grid[0] > 57)
			return (0);
		while (grid[i] >= '0' && grid[i] <= '9')
		{
			nb = ft_strcat(nb, &grid[i], size_nb++);
			i++;
		}
		grid_specs->lines = ft_atoi(nb);
		i++;
	}
	grid_specs->empty = grid[i - 3];
	grid_specs->obstacle = grid[i - 2];
	grid_specs->filled = grid[i - 1];
	if (grid[i + 1] == '\0')
		return (0);
	return (1);
}

int				check_lines(char *grid, t_grid_specs *specs, int i)
{
	int		x;

	x = 0;
	while (grid[i])
	{
		if (grid[i] == specs->empty || grid[i] == specs->filled
			|| grid[i] == specs->obstacle || grid[i] == '\n')
		{
			if (grid[i] == '\n')
			{
				if (x != specs->columns)
					return (0);
				x = -1;
			}
			x++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int				check_grid(char *grid, t_grid_specs *specs)
{
	int		i;
	int		length;
	int		sec_line;

	i = 0;
	if (check_first_line(grid, specs))
	{
		while (grid[i] != '\n')
			i++;
		i++;
	}
	else
		return (0);
	sec_line = i;
	length = i;
	while (grid[length] != '\n' && grid[length] != '\0')
		length++;
	specs->columns = length - i;
	if (!check_lines(grid, specs, i))
		return (0);
	return (sec_line);
}
