/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:28:08 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/20 21:14:50 by akopera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_map
{
	int		*board;
	int		*helper;
	int		number_of_lines;
	int		total_matches;
	int		matches_left;
	int		current_player;
	int		current_line;
}				t_map;

int				get_players_entry(t_map *map);
int				init_game(int fd, t_map *map);
void			print_board(t_map *map);
int				ft_algo(t_map *map);
int				ft_botplays(t_map *map);

#endif
