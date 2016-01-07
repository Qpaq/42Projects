/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akopera <akopera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:13:00 by akopera           #+#    #+#             */
/*   Updated: 2015/12/21 19:08:20 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		ft_whostarts(int i, t_map *map)
{
	if (map->helper[i] == 1)
		return (1);
	else
		return (0);
}

static int		helper_filler(int i, t_map *map)
{
	while (map->board[i] != 0)
	{
		if (map->helper[i + 1] == 1)
		{
			if ((map->board[i] % 4) == 1)
				map->helper[i] = 0;
			else
				map->helper[i] = 1;
		}
		if (map->helper[i + 1] == 0)
		{
			if ((map->board[i] % 4) == 0)
				map->helper[i] = 0;
			else
				map->helper[i] = 1;
		}
		i--;
	}
	i++;
	return (i);
}

int				ft_algo(t_map *map)
{
	int			i;

	i = 0;
	while (map->board[i] != 0)
		i++;
	i--;
	map->helper = (int *)malloc(sizeof(int) * (map->number_of_lines + 1));
	if ((map->board[i] % 4) == 1)
		map->helper[i] = 1;
	else
		map->helper[i] = 0;
	i--;
	i = helper_filler(i, map);
	return (ft_whostarts(i, map));
}

int				ft_botplays(t_map *map)
{
	int			res;

	if (map->helper[map->current_line + 1] == 0
			|| map->current_line == map->number_of_lines)
	{
		if (map->board[map->current_line] % 4 == 0)
			res = 3;
		else
			res = ((map->board[map->current_line] % 4) - 1);
	}
	else
	{
		if ((map->board[map->current_line] % 4) == 0)
			res = 3;
		else
			res = (map->board[map->current_line] % 4);
	}
	return (res);
}
