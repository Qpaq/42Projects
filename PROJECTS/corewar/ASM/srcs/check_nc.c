/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:39:45 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/09 15:45:50 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			check_cmd(char *cmd_line, char *cmd_type, t_cmd *cmd)
{
	char	*cmd_txt;
	int		i;

	i = 0;
	cmd_txt = ft_strsub(cmd_line, ft_strlen(cmd_type),
			ft_strlen(cmd_line) - ft_strlen(cmd_type));
	while (cmd_txt[i] != '\0' && (cmd_txt[i] == ' ' || cmd_txt[i] == '\t'))
		i++;
	if (cmd_txt[i] == '"')
		i++;
	else
		ft_error(1, cmd_type, cmd->nl);
	while (cmd_txt[i] != '\0' && cmd_txt[i] != '"')
		i++;
	if (cmd_txt[i] == '"')
	{
		if (ft_strcmp(cmd_type, NAME_CMD_STRING) == 0)
			cmd->l_name++;
		else if (ft_strcmp(cmd_type, COMMENT_CMD_STRING) == 0)
			cmd->l_comment++;
	}
	ft_memdel((void **)&cmd_txt);
}

static void			get_name(t_cmd *cmd, char *cmd_line)
{
	char *tmp;

	if (cmd->name == NULL)
		cmd->name = ft_strdup(cmd_line);
	else
	{
		tmp = ft_strdup(cmd->name);
		ft_memdel((void **)&cmd->name);
		cmd->name = ft_strjoin(tmp, cmd_line);
		ft_memdel((void **)&tmp);
	}
	cmd->v_name = 1;
	check_cmd(cmd->name, NAME_CMD_STRING, cmd);
}

static void			get_comment(t_cmd *cmd, char *cmd_line)
{
	char	*tmp;

	if (cmd->comment == NULL)
		cmd->comment = ft_strdup(cmd_line);
	else
	{
		tmp = ft_strdup(cmd->comment);
		ft_memdel((void **)&cmd->comment);
		cmd->comment = ft_strjoin(tmp, cmd_line);
		ft_memdel((void **)&tmp);
	}
	cmd->v_comment = 1;
	check_cmd(cmd->comment, COMMENT_CMD_STRING, cmd);
}

void				check_nc(char *line, t_cmd *cmd)
{
	int		i;
	char	*cmd_line;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	cmd_line = ft_strsub(line, i, ft_strlen(line) - i);
	if ((ft_strncmp(cmd_line, NAME_CMD_STRING,
					ft_strlen(NAME_CMD_STRING)) == 0 && (cmd->l_name++))
			|| cmd->l_name == 1)
		get_name(cmd, cmd_line);
	else if ((ft_strncmp(cmd_line, COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)) == 0
				&& (cmd->l_comment++)) || cmd->l_comment == 1)
		get_comment(cmd, cmd_line);
	ft_memdel((void **)&cmd_line);
	if (cmd->l_name == 2 && cmd->l_comment == 2 && cmd->nc == 0)
		end_nc(cmd);
}
