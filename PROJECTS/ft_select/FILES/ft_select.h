/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:50:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/11 19:22:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>

typedef struct	s_args_list
{
	char				*value;
	int					selected;
	struct s_args_list	*next;
}				t_args_list;

typedef struct	s_select
{
	int			win_x;
	int			win_y;
	int			curs_x;
	int			curs_y;
	size_t		max_length;
	t_args_list	*list;
	int			size_list;
}				t_select;

int				putchar_select(int c);
void			ft_move_cursor(t_select *params);
void			ft_tputs(char *cap);
t_args_list		*return_current_element(t_select *params);
void			add_visual_effects(t_args_list *element, t_select *params);

void			parse_arguments(int argc, char **argv, t_select *params);
void			print_list(t_select *params);
void			return_list(t_select *params);
void			free_args_list(t_args_list *head);
void			free_select_struct(t_select **params);

int				init_raw_mode(void);
int				restore_terminal(void);

void			get_key_pressed(t_select *params);
void			return_key_pressed(t_select *params);
void			space_key_pressed(t_select *params);
void			arrow_key_pressed(int key, t_select *params);

void			ft_signals(void);

#endif
