/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:55:10 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/16 21:55:22 by jchevali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

char	**read_from_file(char *file)
{
	int		ret;
	int		fd;
	char	letter;
	char	**grid;
	int		i;

	fd = open(file, O_RDONLY);
	grid = (char**)malloc(sizeof(char*) * 9);
	i = 0;
	while (ret = read(fd, letter, 1))
	{
		grid[i] = (char*)malloc(sizeof(char) * 10);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	**sudo_tb;
	int		index;
	int		index_malloc;

	index_malloc = 0;
	if (argc == 10 && is_valid_number(argv) == 1)
	{
		index = 0;
		sudo_tb = (char**)malloc(9 * sizeof(char*));
		while (index_malloc < 9)
		{
			sudo_tb[index_malloc] = (char*)malloc(10 * sizeof(char));
			index_malloc++;
		}
		copy_sudo(argv, sudo_tb);
		if (is_valid_char(argv) == 1 && sudoku(sudo_tb, 0))
			print_sudoku(sudo_tb);
		else
			write(1, "Erreur\n", 7);
		free_grid(sudo_tb);
	}
	else
		write(1, "Errer\n", 7);
	return (0);
}
