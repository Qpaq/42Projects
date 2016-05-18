/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 21:52:58 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:10:31 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			init(t_cmd *cmd)
{
	cmd->v_name = 0;
	cmd->l_name = 0;
	cmd->name = NULL;
	cmd->v_comment = 0;
	cmd->l_comment = 0;
	cmd->comment = NULL;
	cmd->nc = 0;
	cmd->nl = 0;
	cmd->nb_instr = 0;
	cmd->label = NULL;
}

void			free_cmd(t_cmd *cmd)
{
	t_label		*g_label;

	ft_memdel((void **)&cmd->name);
	ft_memdel((void **)&cmd->comment);
	while (cmd->label != NULL)
	{
		g_label = cmd->label;
		cmd->label = cmd->label->next;
		ft_memdel((void **)&g_label->name);
		ft_memdel((void **)&g_label);
	}
	ft_memdel((void **)&cmd);
}
