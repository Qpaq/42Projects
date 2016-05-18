/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 16:00:04 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:20:19 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_new_label(char *name, int kind, t_cmd *cmd)
{
	t_label		*g_label;
	t_label		*new_label;

	if (!(new_label = (t_label *)malloc(sizeof(t_label))))
		ft_error(0, NULL, cmd->nl);
	if (cmd->label != NULL)
	{
		g_label = cmd->label;
		while (g_label != NULL && g_label->next != NULL)
			g_label = g_label->next;
	}
	new_label->name = ft_strdup(name);
	new_label->kind = kind;
	new_label->next = NULL;
	if (cmd->label == NULL)
		cmd->label = new_label;
	else
		g_label->next = new_label;
}
