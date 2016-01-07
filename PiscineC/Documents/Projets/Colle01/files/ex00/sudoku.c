/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevali <jchevali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:59:55 by jchevali          #+#    #+#             */
/*   Updated: 2015/08/16 21:54:22 by jchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_valid_char(char **line)
{
	int	i;
	int i2;

	i = 1;
	i2 = 0;
	while (i <= 9)
	{
		while (i2 < 9)
		{
			if (line[i][i2] < '1' || line[i][i2] > '9')
			{
				if (line[i][i2] != '.')
					return (0);
			}
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (1);
}

int		sudoku(char **grid, int position)
{
	int		line;
	int		column;
	char	nb;

	line = position / 9;
	column = position % 9;
	nb = '1';
	if (position == 81)
		return (1);
	if (grid[line][column] != '.')
		return (sudoku(grid, position + 1));
	while (nb <= '9')
	{
		if (number_is_valid(nb, grid, line, column))
		{
			grid[line][column] = nb;
			if (sudoku(grid, position + 1))
				return (1);
		}
		nb++;
	}
	grid[line][column] = '.';
	return (0);
}

void	copy_sudo(char **original_grid, char **copy)
{
	int		line;
	int		column;

	line = 1;
	column = 0;
	while (line <= 9)
	{
		while (original_grid[line][column] != '\0')
		{
			copy[line - 1][column] = original_grid[line][column];
			column++;
		}
		copy[line - 1][column] = '\0';
		column = 0;
		line++;
	}
}

void	free_grid(char **grid)
{
	int		index;

	index = 0;
	while (index < 9)
	{
		free(grid[index]);
		index++;
	}
	free(grid);
}

void	print_sudoku(char **final_grid)
{
	int		line;
	int		number;

	line = 0;
	number = 0;
	while (line < 9)
	{
		while (final_grid[line][number] != '\0')
		{
			write(1, &final_grid[line][number], 1);
			if (number != 8)
				write(1, " ", 1);
			number++;
		}
		write(1, "\n", 1);
		number = 0;
		line++;
	}
}
