/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:04:51 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:35:49 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_line(int opcode)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (g_op_tab[i].op_code == opcode)
			return (i);
		else
			i++;
	}
	return (-1);
}

static char		*get_instruction(char *line)
{
	char	*line_t;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strtrim(line);
	while (tmp[i] != '\0' && tmp[i] != COMMENT_CHAR && tmp[i] != ';')
		i++;
	line_t = ft_strsub(tmp, 0, i);
	ft_memdel((void **)&tmp);
	return (line_t);
}

void			check_instr(char *line, int opcode, t_cmd *cmd)
{
	char	**instr;
	char	*in_line;
	char	*tmp;
	int		i;

	i = ft_strlen(g_op_tab[get_line(opcode)].name);
	tmp = get_instruction(line);
	in_line = ft_strsub(tmp, i, ft_strlen(tmp) - i);
	ft_memdel((void **)&tmp);
	i = 0;
	instr = ft_strsplit(in_line, SEPARATOR_CHAR);
	while (instr[i] != NULL)
	{
		tmp = ft_strtrim(instr[i]);
		if (!(get_kind_arg(tmp, cmd) & g_op_tab[get_line(opcode)].args[i]))
			ft_error(4, NULL, cmd->nl);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&instr[i]);
		i++;
	}
	if (i < g_op_tab[get_line(opcode)].nb_args)
		ft_error(4, NULL, cmd->nl);
	ft_memdel((void **)&instr);
	ft_memdel((void **)&in_line);
	cmd->nb_instr++;
}
