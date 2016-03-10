/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:12:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/09 11:24:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putchar_select(int c)
{
	int		fd;

	fd = open(ttyname(0), O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (1);
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
	return (params);
}


void	screen_size(t_select *params)
{
	int		col;
	int		li;
	
	col = tgetnum("co");
	li = tgetnum("li");
	params->win_x = col;
	params->win_y = li;
}



int		main(int argc, char **argv)
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
	screen_size(params);
	print_list(params);
	get_key(params);
	restore_terminal();
	return (0);
}
