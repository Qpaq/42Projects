/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_nc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 22:58:16 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:54:27 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			get_end_nc(char *cmd_line, t_cmd *cmd)
{
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0;
	while (cmd_line[i] != '\0' && j < 2)
		if (cmd_line[i++] == '"')
			j++;
	t = i;
	j = 0;
	while (cmd_line[i] != '\0')
	{
		if (cmd_line[i] != ' ' && cmd_line[i] != '\t' && j == 0)
		{
			if (cmd_line[i] == ';' || cmd_line[i] == '#')
				j = i;
			else
				ft_error(2, &cmd_line[i], cmd->nl);
		}
		i++;
	}
	return (t);
}

static int			get_start_nc(char *cmd_line)
{
	int		i;

	i = 0;
	while (cmd_line[i] != '\0' && cmd_line[i] != '"')
		i++;
	return (i + 1);
}

void				end_nc(t_cmd *cmd)
{
	char	*tmp;
	int		end;
	int		start;

	start = get_start_nc(cmd->name);
	end = get_end_nc(cmd->name, cmd);
	tmp = ft_strdup(cmd->name);
	ft_memdel((void **)&cmd->name);
	cmd->name = ft_strsub(tmp, start, end - start - 1);
	ft_memdel((void **)&tmp);
	start = get_start_nc(cmd->comment);
	end = get_end_nc(cmd->comment, cmd);
	tmp = ft_strdup(cmd->comment);
	ft_memdel((void **)&cmd->comment);
	cmd->comment = ft_strsub(tmp, start, end - start - 1);
	ft_memdel((void **)&tmp);
	cmd->nc = 1;
}
