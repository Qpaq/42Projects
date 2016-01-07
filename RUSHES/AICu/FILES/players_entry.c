/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 12:43:40 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/20 19:46:54 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		check_players_entry(char *line, t_map *map)
{
	int		i;
	int		result;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	result = ft_atoi(line);
	if (result > map->board[map->current_line])
	{
		ft_putcolor("ATTENTION! There are only ", "red");
		ft_putnbr(map->board[map->current_line]);
		ft_putcolor(" matches left on this line\n", "red");
		return (-1);
	}
	return (result);
}

void	print_instructions_for_player(t_map *map)
{
	ft_putcolor("Your turn! ", "green");
	ft_putcolor("You can take between 1 and 3 matches ", "green");
	ft_putcolor("(0 or <enter> to exit)\n", "light red");
	print_board(map);
	ft_putchar('\n');
	ft_putcolor("Matches: ", "green");
	ft_putnbr(map->matches_left);
	ft_putcolor(" / ", "green");
	ft_putnbr(map->total_matches);
	ft_putchar('\n');
}

int		get_players_entry(t_map *map)
{
	char	*entry;
	int		number;

	number = -1;
	while ((number < 1 || number > 3) || (map->matches_left - number < 0))
	{
		if (number == 0)
			return (0);
		print_instructions_for_player(map);
		get_next_line(0, &entry);
		number = check_players_entry(entry, map);
	}
	return (number);
}
