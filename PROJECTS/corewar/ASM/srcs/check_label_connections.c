/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label_connections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 20:36:33 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:24:44 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		conn_label(char *name, t_cmd *cmd)
{
	t_label		*g_label;

	g_label = cmd->label;
	while (g_label != NULL)
	{
		if (ft_strcmp(g_label->name, name) == 0 && g_label->kind == IS_LABEL)
			return (1);
		else
			g_label = g_label->next;
	}
	return (0);
}

void			check_label_connections(t_cmd *cmd)
{
	t_label		*g_label;

	if (cmd->label != NULL)
	{
		g_label = cmd->label;
		while (g_label != NULL)
		{
			if (g_label->kind == A_VERIF && conn_label(g_label->name, cmd) == 0)
				ft_error(6, g_label->name, cmd->nl);
			else
				g_label = g_label->next;
		}
	}
}
