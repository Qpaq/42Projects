/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:22:28 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:23:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			putchar_select(int c)
{
	int		fd;

	fd = open(ttyname(0), O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (1);
}

void		ft_move_cursor(t_select *params)
{
	tputs(tgoto(tgetstr("cm", NULL), 0, params->curs_y), 1, putchar_select);
}

void		ft_tputs(char *cap)
{
	tputs(tgetstr(cap, NULL), 1, putchar_select);
}

t_args_list	*return_current_element(t_select *params)
{
	t_args_list		*element;
	int				i;

	i = 0;
	element = params->list;
	while (i < params->curs_y)
	{
		element = element->next;
		i++;
	}
	return (element);
}

void		add_visual_effects(t_args_list *element, t_select *params)
{
	t_args_list		*current;

	current = return_current_element(params);
	if (element->selected)
		ft_tputs("mr");
	if (element == current)
		ft_tputs("us");
	ft_putendl(element->value);
	ft_tputs("me");
	ft_tputs("ue");
}
