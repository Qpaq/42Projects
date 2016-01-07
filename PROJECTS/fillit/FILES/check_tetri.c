/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:28:30 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 10:32:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*shift_left(int *pos)
{
	int				mod;

	mod = pos[0] % 4;
	if (pos[1] % 4 < mod)
		mod = pos[1] % 4;
	if (pos[2] % 4 < mod)
		mod = pos[2] % 4;
	if (pos[3] % 4 < mod)
		mod = pos[3] % 4;
	mod = (mod + ((pos[0] / 4) * 4));
	pos[0] = pos[0] - mod;
	pos[1] = pos[1] - mod;
	pos[2] = pos[2] - mod;
	pos[3] = pos[3] - mod;
	return (pos);
}

int			check_tetriminos(char *tetri)
{
	int				sharp_count;
	int				connections;

	connections = 0;
	sharp_count = 0;
	while (*tetri)
	{
		if (*tetri != '.' && *tetri != '#')
			return (0);
		if (*tetri == '#' && ++sharp_count)
		{
			if (*(tetri - 1) == '#')
				connections++;
			if (*(tetri + 1) == '#')
				connections++;
			if (*(tetri - 4) == '#')
				connections++;
			if (*(tetri + 4) == '#')
				connections++;
		}
		tetri++;
	}
	if (sharp_count == 4 && (connections == 6 || connections == 8))
		return (1);
	return (0);
}
