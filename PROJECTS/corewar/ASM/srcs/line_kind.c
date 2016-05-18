/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_kind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:06:44 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/09 15:46:16 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_instr(char *line_t)
{
	char	*instr;
	int		i;

	i = 0;
	while (line_t[i] != '\0' && line_t[i] != ' ' && line_t[i] != '\t')
		i++;
	instr = ft_strsub(line_t, 0, i);
	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (ft_strcmp(instr, g_op_tab[i].name) == 0)
		{
			ft_memdel((void **)&instr);
			return (g_op_tab[i].op_code * 10);
		}
		i++;
	}
	ft_memdel((void **)&instr);
	return (-1);
}

static int		is_label(char *line_t)
{
	int		i;
	int		ret;
	char	*lc;

	lc = ft_strdup(LABEL_CHARS);
	i = 0;
	ret = -1;
	while (line_t[i] != '\0')
	{
		if (line_t[i] == LABEL_CHAR && i > 0)
		{
			ret = 1;
			break ;
		}
		else if (ft_strchr(lc, line_t[i]) == NULL)
			break ;
		else
			i++;
	}
	ft_memdel((void **)&lc);
	return (ret);
}

static char		*get_label_name(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	j = i;
	while (line[j] != LABEL_CHAR)
		j++;
	return (ft_strsub(line, i, j - i));
}

void			check_label(char *line, t_cmd *cmd)
{
	int		i;
	char	*instr;
	char	*line_t;
	char	*label_name;

	i = 1;
	label_name = get_label_name(line);
	get_new_label(label_name, IS_LABEL, cmd);
	ft_memdel((void **)&label_name);
	while (line[i - 1] != LABEL_CHAR)
		i++;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] != '\0')
	{
		instr = ft_strsub(line, i, ft_strlen(line) - i);
		line_t = ft_strtrim(instr);
		ft_memdel((void **)&instr);
		if (get_instr(line_t) >= 10)
			check_instr(line_t, get_instr(line_t) / 10, cmd);
		else
			ft_error(4, NULL, cmd->nl);
		ft_memdel((void **)&line_t);
	}
}

int				line_kind(char *line)
{
	char	*line_t;
	int		ret;

	line_t = ft_strtrim(line);
	if (line_t[0] == '\0')
		ret = 0;
	else if (line_t[0] == COMMENT_CHAR)
		ret = 1;
	else if (line_t[0] == ';')
		ret = 2;
	else if (ft_strncmp(line_t, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) == 0)
		ret = 3;
	else if (ft_strncmp(line_t, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0)
		ret = 4;
	else if (is_label(line_t) == 1)
		ret = 5;
	else
		ret = get_instr(line_t);
	ft_memdel((void **)&line_t);
	return (ret);
}
