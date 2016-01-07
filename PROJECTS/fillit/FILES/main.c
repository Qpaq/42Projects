/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:18:13 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 11:18:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	init_tab(int **pos, int square_size, int size)
{
	int j;

	j = 0;
	while (j < size && square_size < 4)
	{
		if (pos[j][3] == 3 || pos[j][3] == 12)
			return (0);
		if (square_size == 2 && pos[j][0] != 0 && pos[j][1] != 1
			&& pos[j][2] != 4 && pos[j][3] != 5)
			return (0);
		j++;
	}
	j = 0;
	while (j < size)
	{
		pos[j][1] = (pos[j][1] / 4) * (square_size - 4) + pos[j][1];
		pos[j][2] = (pos[j][2] / 4) * (square_size - 4) + pos[j][2];
		pos[j][3] = (pos[j][3] / 4) * (square_size - 4) + pos[j][3];
		j++;
	}
	return (1);
}

static void	fillit_print(char *fmap, int square_size)
{
	int i;
	int j;

	i = 0;
	j = square_size * square_size;
	while (i < j)
	{
		ft_putchar(fmap[i++]);
		while (i % square_size)
			ft_putchar(fmap[i++]);
		ft_putchar('\n');
	}
}

int			fillit(int fd)
{
	t_fmap	*c_map;
	char	fmap[1024];
	int		i;

	i = 0;
	if (!(c_map = (t_fmap *)malloc(sizeof(t_fmap))))
		return (0);
	if (!check_file(fd, c_map))
		return (0);
	while (i < 1023)
		fmap[i++] = '.';
	fmap[i] = '\0';
	while (!init_tab(c_map->tab, c_map->square_size, c_map->size))
		c_map->square_size++;
	while (1)
	{
		if (backtrack_tetri(c_map, fmap, 0))
		{
			fillit_print(fmap, c_map->square_size);
			return (1);
		}
		increment_square_size(c_map);
		c_map->square_size++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		ft_putendl("error");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putendl("error");
			return (0);
		}
		if (!fillit(fd))
			ft_putendl("error");
		close(fd);
	}
	return (0);
}
