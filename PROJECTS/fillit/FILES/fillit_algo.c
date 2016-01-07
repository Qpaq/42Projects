/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:19:28 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 11:19:29 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt_max(int nbr)
{
	int sqrt;
	int max;
	int min;
	int tmp;

	if (nbr < 2)
		return (nbr);
	min = 0;
	if (nbr / 2 > 46340)
		max = 46341;
	else
		max = nbr / 2;
	while (max - min > 1)
	{
		sqrt = (max + min) / 2;
		tmp = sqrt * sqrt;
		if (tmp == nbr)
			return (sqrt);
		else if (tmp > nbr)
			max = sqrt;
		else
			min = sqrt;
	}
	return (max);
}

void		increment_square_size(t_fmap *map)
{
	int		i;
	int		**tab;

	tab = map->tab;
	while (*tab)
	{
		i = 0;
		while (i < 4)
		{
			*(*tab + i) = *(*tab + i) + (*(*tab + i) / map->square_size);
			i++;
		}
		tab++;
	}
}

static int	check_shift(int *pos, int shift, int square_size)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((pos[i] + shift + 1) % square_size == 0)
			break ;
		else if (i == 3)
			return (shift + 1);
		i++;
	}
	i = (pos[3] + shift) / square_size;
	if (i++ < square_size - 1)
		return ((i - (pos[3] / square_size)) * square_size);
	else
		return (-1);
}

static char	*pos_fmap(int *pos, char *fmap, int shift, int line)
{
	char	c;

	c = 'A' + line;
	fmap[pos[0] + shift] = c;
	fmap[pos[1] + shift] = c;
	fmap[pos[2] + shift] = c;
	fmap[pos[3] + shift] = c;
	return (fmap);
}

int			backtrack_tetri(t_fmap *tetri, char *fmap, int line)
{
	int shift;
	int	*pos;

	shift = 0;
	pos = tetri->tab[line];
	if (line >= tetri->size)
		return (1);
	while (shift >= 0)
	{
		if (fmap[pos[0] + shift] == '.' &&
			fmap[pos[1] + shift] == '.' &&
			fmap[pos[2] + shift] == '.' &&
			fmap[pos[3] + shift] == '.')
		{
			fmap = pos_fmap(pos, fmap, shift, line);
			if (backtrack_tetri(tetri, fmap, line + 1))
				return (1);
			fmap[pos[0] + shift] = '.';
			fmap[pos[1] + shift] = '.';
			fmap[pos[2] + shift] = '.';
			fmap[pos[3] + shift] = '.';
		}
		shift = check_shift(pos, shift, tetri->square_size);
	}
	return (0);
}
