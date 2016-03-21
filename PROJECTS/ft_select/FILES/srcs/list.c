/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:23:32 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:23:38 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_args_list(t_args_list *head)
{
	t_args_list		*next;

	while (head)
	{
		ft_memdel((void **)&(head->value));
		next = head->next;
		ft_memdel((void **)&head);
		head = next;
	}
}

void	free_select_struct(t_select **params)
{
	free_args_list((*params)->list);
	ft_memdel((void **)params);
}

void	return_list(t_select *params)
{
	t_args_list	*current;
	int			space;

	space = 0;
	current = params->list;
	while (current)
	{
		if (current->selected)
		{
			if (space)
				ft_putchar(' ');
			ft_putstr(current->value);
			space = 1;
		}
		current = current->next;
	}
	free_select_struct(&params);
}

void	print_list(t_select *params)
{
	t_args_list	*element;

	element = params->list;
	ft_tputs("cl");
	if (params->curs_y == params->size_list)
		params->curs_y = 0;
	if (params->curs_y == -1)
		params->curs_y = params->size_list - 1;
	while (element)
	{
		add_visual_effects(element, params);
		element = element->next;
	}
	ft_move_cursor(params);
}

void	parse_arguments(int argc, char **argv, t_select *params)
{
	int			i;
	t_args_list	*new;
	t_args_list	*list;

	list = params->list;
	list->value = ft_strdup(argv[0]);
	params->max_length = ft_strlen(argv[0]);
	i = 1;
	while (i < argc)
	{
		new = (t_args_list *)ft_memalloc(sizeof(t_args_list));
		new->value = ft_strdup(argv[i]);
		list->next = new;
		list = list->next;
		if (params->max_length < ft_strlen(argv[i]))
			params->max_length = ft_strlen(argv[i]);
		i++;
	}
	params->size_list = i;
}
