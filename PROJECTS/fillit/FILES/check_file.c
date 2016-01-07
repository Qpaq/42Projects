/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:05:31 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 10:29:46 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			*return_pos_sharps(char *str)
{
	int				*line;
	int				*ptr;
	int				i;

	line = (int *)malloc(sizeof(int) * 4);
	i = 0;
	ptr = line;
	while (str[i])
	{
		if (str[i] == '#')
		{
			*ptr = i;
			ptr++;
		}
		i++;
	}
	return (line);
}

static int			init_struct(t_fmap *c_map, int lines, char *last_line)
{
	int				i;

	i = 4;
	c_map->size = lines / 5;
	c_map->square_size = 4;
	c_map->square_size = ft_sqrt_max(4 * (lines / 5));
	if (lines % 5 != 0 || ft_strlen(last_line) != 0)
		return (0);
	return (1);
}

static int			copy_to_struct(char *cur_tetri, int itab, t_fmap *c_map)
{
	if (!check_tetriminos(cur_tetri))
		return (0);
	c_map->tab[itab] = return_pos_sharps(cur_tetri);
	c_map->tab[itab] = shift_left(c_map->tab[itab]);
	itab++;
	return (itab);
}

static int			check_file_bis(int fd, t_fmap *c_map, int line_nb, int itab)
{
	char			*line;
	char			*cur_tetri;
	int				i;

	cur_tetri = ft_strnew(1);
	i = 4;
	while (++line_nb && get_next_line(fd, &line))
	{
		if (line_nb % 5 != 0)
		{
			if (ft_strlen(line) != 4)
				return (0);
			cur_tetri = ft_strjoin(cur_tetri, line);
		}
		if (((line_nb % 5) == 0 && ft_strlen(line) != 0) || (line_nb / 5) > 26)
			return (0);
		if (line_nb == i && (i = i + 5))
		{
			if (!(itab = copy_to_struct(cur_tetri, itab, c_map)))
				return (0);
			cur_tetri = ft_strnew(1);
		}
	}
	c_map->tab[itab] = NULL;
	return (init_struct(c_map, line_nb, line));
}

int					check_file(int fd, t_fmap *c_map)
{
	int		line_nb;
	int		itab;

	line_nb = 0;
	itab = 0;
	if (!check_file_bis(fd, c_map, line_nb, itab))
		return (0);
	return (1);
}
