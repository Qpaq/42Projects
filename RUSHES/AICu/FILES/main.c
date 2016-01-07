/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:26:41 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/21 19:34:49 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

void			print_board(t_map *map)
{
	int		*tab;
	int		i;

	tab = map->board;
	while (*tab)
	{
		if (*tab != -1)
		{
			i = 0;
			while (i < *tab)
			{
				ft_putchar('|');
				if (i < *tab - 1)
					ft_putchar(' ');
				i++;
			}
			ft_putchar('\n');
		}
		tab++;
	}
}

static int		take_turns(t_map *map)
{
	int		nb_of_matches;

	if (map->current_player == 0)
	{
		nb_of_matches = ft_botplays(map);
		ft_putcolor("The bot played and took ", "red");
		ft_putnbr(nb_of_matches);
		ft_putcolor(" matches.\n", "red");
		map->current_player += 1;
	}
	else
	{
		if (!(nb_of_matches = get_players_entry(map)))
			return (0);
		map->current_player -= 1;
	}
	return (nb_of_matches);
}

int				aicu(int fd, t_map *map)
{
	int		nb_of_matches;

	if (!init_game(fd, map))
		return (0);
	while (map->matches_left > 0)
	{
		if (!(nb_of_matches = take_turns(map)))
			return (0);
		map->matches_left -= nb_of_matches;
		map->board[map->current_line] -= nb_of_matches;
		if (map->board[map->current_line] == 0)
		{
			map->board[map->current_line] = -1;
			map->current_line += 1;
		}
	}
	if (map->current_player == 0)
		ft_putrainbow("THE BOT WINS\n");
	else
		ft_putrainbow("YOU WIN\n");
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->total_matches = 0;
	map->number_of_lines = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
	}
	else
		return (0);
	if (!aicu(fd, map))
		return (0);
	return (0);
}
