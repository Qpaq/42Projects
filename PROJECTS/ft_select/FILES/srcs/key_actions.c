/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:22:19 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:22:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	space_key_pressed(t_select *params)
{
	t_args_list		*element;

	element = return_current_element(params);
	element->selected = element->selected ? 0 : 1;
	params->curs_y += 1;
	print_list(params);
}

void	return_key_pressed(t_select *params)
{
	restore_terminal();
	return_list(params);
	exit(0);
}

void	arrow_key_pressed(int key, t_select *params)
{
	if (key == 1 || key == 2)
	{
		if (key == 1 && params->curs_y >= 0)
			params->curs_y -= 1;
		if (key == 2 && params->curs_y < params->size_list)
			params->curs_y += 1;
		print_list(params);
	}
}
