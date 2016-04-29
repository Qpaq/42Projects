/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:19:16 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 19:19:19 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct		s_rooms
{
	char			*name;
	int				pos_x;
	int				pos_y;
	int				nb_of_connections;
	char			**connections;
	int				is_start;
	int				is_end;
	int				busy;
	int				weight;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_open
{
	t_rooms			*room;
	struct s_open	*next;
	struct s_open	*prev;
}					t_open;

typedef struct		s_close
{
	t_rooms			*room;
	struct s_close	*next;
}					t_close;

typedef struct		s_ant
{
	int				num;
	char			*current_room;
	int				arrived;
	struct s_ant	*next;
}					t_ant;

t_rooms				*get_room_from_name(char *room, t_rooms *rooms);
char				*get_best_room(t_rooms *rooms, char *current);
int					get_room_weight(char *room, t_rooms *rooms);

int					print_rooms(t_rooms *rooms);
void				all_engine_running(t_rooms *rooms, int nb_ants);

/*
** PARSING
*/
void				parse_file(t_rooms **rooms
		, int start, int end, char **file);

/*
** CREATE ROOMS
*/
t_rooms				*add_room(t_rooms *head, char **line, int start, int end);
int					add_con(t_rooms *rooms, char **line, int ret);

/*
** ALGO
*/
t_open				*init_open(t_rooms *end);
t_open				*add_to_open(t_open *open_list, t_rooms *room);
t_open				*remove_from_open(t_open *open_list, t_rooms *room);
t_close				*add_to_close(t_close *close_list, t_rooms *room);
t_rooms				*get_current(t_open *open_list);
int					is_in_close(t_close *close_list, t_rooms *connection);
int					is_in_open(t_open *open_list, t_rooms *connection);
void				algo_path(t_rooms *start, t_open *open_list,
		t_close *close_list);
int					get_path(t_rooms *end, t_rooms *start);

/*
** MOVE
*/
int					all_arrived(t_ant *ant);
char				*check_other_rooms(t_rooms *rooms, char *current_name,
		int best_weight);
char				*get_start_room_name(t_rooms *rooms);
void				print_room_state(t_rooms *rooms);
void				all_engine_running(t_rooms *rooms, int nb_ants);
t_ant				*create_ants(int count, char *start_room);
t_ant				*append_ant(t_ant *head, int num, char *start_room);
void				proceed_steps(t_rooms *rooms, t_ant *ant);
void				go_to(char *from, char *to, t_ant *ant, t_rooms *rooms);

#endif
