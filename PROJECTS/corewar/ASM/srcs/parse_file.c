/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 12:28:58 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/11 17:15:52 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				parse_file(char *champ)
{
	int		fd;
	char	*line;
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	fd = open(champ, O_RDONLY);
	init(cmd);
	while (get_next_line(fd, &line) > 0)
	{
		cmd->nl++;
		if (cmd->l_name == 1 || cmd->l_comment == 1
				|| (line_kind(line) < 5 && line_kind(line) >= 0))
			check_nc(line, cmd);
		else if (line_kind(line) == 5)
			check_label(line, cmd);
		else if (line_kind(line) >= 10 && cmd->nc == 1)
			check_instr(line, line_kind(line) / 10, cmd);
		else
			ft_error((cmd->nc == 0) ? 2 : 3, NULL, cmd->nl);
		free(line);
	}
	(cmd->nb_instr == 0) ? ft_error(8, NULL, cmd->nl) : NULL;
	check_size_nc(cmd);
	check_label_connections(cmd);
	free_cmd(cmd);
}
