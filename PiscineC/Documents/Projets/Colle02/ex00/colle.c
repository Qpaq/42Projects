/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 09:08:39 by alhote            #+#    #+#             */
/*   Updated: 2015/08/23 20:31:44 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle.h"

void				print_informations(t_rectangle_spec **colles)
{
	int	i;
	int b;

	b = 0;
	i = 0;
	while (i <= 4)
	{
		if (colles[i]->colle)
		{
			if (b)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(colles[i]->size_x);
			ft_putstr("] [");
			ft_putnbr(colles[i]->size_y);
			ft_putstr("]");
			b = 1;
		}
		i++;
	}
	if (!b)
		ft_putstr("aucune");
	ft_putstr("\n");
}

void				put_size(int *size_x, int *size_y, int x, int y)
{
	*size_x = x;
	*size_y = y;
}

int					get_size(int *size_x, int *size_y, char *rectangle)
{
	int		x;
	int		y;
	int		i;
	int		x2;

	x = 0;
	x2 = 0;
	y = 0;
	i = 0;
	while (rectangle[x] != '\n' && rectangle[x] != '\0')
		x++;
	while (rectangle[i] != '\0')
	{
		if (rectangle[i] == '\n')
		{
			if (x2 != x)
				return (1);
			x2 = -1;
			y++;
		}
		i++;
		x2++;
	}
	put_size(size_x, size_y, x, y);
	return (0);
}

t_rectangle_spec	*init_struct(char *spec, int size_x, int size_y)
{
	t_rectangle_spec	*tmp;

	tmp = (t_rectangle_spec*)malloc(sizeof(t_rectangle_spec));
	tmp->colle = 0;
	tmp->hg = spec[0];
	tmp->hd = spec[1];
	tmp->bg = spec[2];
	tmp->bd = spec[3];
	tmp->ch = spec[4];
	tmp->cc = spec[5];
	tmp->size_x = size_x;
	tmp->size_y = size_y;
	return (tmp);
}

void				colle(char *rectangle)
{
	int					size_x;
	int					size_y;
	t_rectangle_spec	**colles;

	colles = (t_rectangle_spec**)malloc(5 * sizeof(t_rectangle_spec*));
	if (!get_size(&size_x, &size_y, rectangle))
	{
		colles[0] = init_struct("oooo-|", size_x, size_y);
		colles[1] = init_struct("/\\\\/**", size_x, size_y);
		colles[2] = init_struct("AACCBB", size_x, size_y);
		colles[3] = init_struct("ACACBB", size_x, size_y);
		colles[4] = init_struct("ACCABB", size_x, size_y);
		try_parse(colles[0], rectangle);
		try_parse(colles[1], rectangle);
		try_parse(colles[2], rectangle);
		try_parse(colles[3], rectangle);
		try_parse(colles[4], rectangle);
		print_informations(colles);
	}
	else
		ft_putstr(MSG_ERREUR);
}
