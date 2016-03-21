/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:23:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:23:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		screen_size(t_select *params)
{
	int		col;
	int		li;

	col = tgetnum("co");
	li = tgetnum("li");
	params->win_x = col;
	params->win_y = li;
}

t_select	*init_struct(void)
{
	t_select	*params;
	t_args_list	*head_list;

	if ((params = (t_select *)ft_memalloc(sizeof(t_select))) == NULL)
		return (NULL);
	if ((head_list = (t_args_list *)ft_memalloc(sizeof(t_args_list))) == NULL)
		return (NULL);
	params->list = head_list;
	screen_size(params);
	return (params);
}

int			main(int argc, char **argv)
{
	char			*term_name;
	t_select		*params;

	if (argc <= 1)
		return (-1);
	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putendl("Cannot find environment variable TERM");
		return (-1);
	}
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (init_raw_mode() == -1)
		return (-1);
	params = init_struct();
	parse_arguments(--argc, ++argv, params);
	ft_signals();
	print_list(params);
	get_key_pressed(params);
	restore_terminal();
	free_select_struct(&params);
	return (0);
}
