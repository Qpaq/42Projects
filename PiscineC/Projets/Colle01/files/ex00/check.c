/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:15:18 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/16 21:54:09 by jchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_valid_number(char **lines)
{
	int i1;
	int i2;

	i1 = 1;
	i2 = 0;
	while (i1 <= 9)
	{
		while (lines[i1][i2] != '\0')
		{
			if (i2 > 8)
				return (0);
			i2++;
		}
		if (i2 < 9)
			return (0);
		i2 = 0;
		i1++;
	}
	return (1);
}

int		check_line(char nb, char **grid, int line_number)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (grid[line_number][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		check_column(char nb, char **grid, int col_number)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col_number] == nb)
			return (0);
		i++;
	}
	return (1);
}

int		check_square(char nb, char **grid, int line_number, int col_number)
{
	int		i;
	int		j;
	int		i2;
	int		j2;

	i = line_number - (line_number % 3);
	j = col_number - (col_number % 3);
	i2 = i + 2;
	j2 = j + 2;
	while (i <= i2)
	{
		while (j <= j2)
		{
			if (grid[i][j] == nb)
				return (0);
			j++;
		}
		j -= 2;
		i++;
	}
	return (1);
}

int		number_is_valid(char nb, char **grid, int line_number, int col_number)
{
	if (check_column(nb, grid, col_number) == 0)
		return (0);
	else if (check_line(nb, grid, line_number) == 0)
		return (0);
	else if (check_square(nb, grid, line_number, col_number) == 0)
		return (0);
	return (1);
}
