/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:59 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 17:04:01 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	strip_comments(char **line)
{
	size_t	i;
	char	*tmp;
	char	*stripped;

	i = 0;
	while ((*line)[i] != ';' && (*line)[i] != COMMENT_CHAR
			&& i < ft_strlen(*line))
		i++;
	tmp = ft_strnew(i);
	i = 0;
	while ((*line)[i] != ';' && (*line)[i] != COMMENT_CHAR
			&& i < ft_strlen(*line))
	{
		tmp[i] = (*line)[i];
		i++;
	}
	free(*line);
	stripped = ft_strtrim(tmp);
	free(tmp);
	*line = stripped;
}

void	fill_link(t_instruct *new, char *line, int pos)
{
	new->label = get_inst_label(&line);
	new->instruction = get_inst_name(&line);
	new->arguments = get_inst_args(line);
	new->position = pos;
	new->size = get_inst_size(new->arguments, new);
	new->ocp = get_ocp(new->arguments, new->instruction);
	new->next = NULL;
}

void	add_instruction_to_list(char *line, t_instruct **instruct)
{
	t_instruct	*head;
	t_instruct	*new;
	int			pos;

	head = *instruct;
	pos = 0;
	if ((new = (t_instruct *)ft_memalloc(sizeof(t_instruct))) == NULL)
		error_exit("Error malloc()");
	while (head->next)
	{
		pos += head->size;
		head = head->next;
	}
	pos += head->size;
	fill_link(new, line, pos);
	if ((*instruct)->position == -1)
	{
		free(*instruct);
		*instruct = new;
	}
	else
		head->next = new;
}

int		line_has_label(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
	{
		if (ft_strchr(LABEL_CHARS, line[i]) == NULL)
			return (0);
		i++;
	}
	if (line[i] == LABEL_CHAR)
		return (i);
	return (0);
}

int		get_instructions(int fd, t_instruct **instruct)
{
	int		ret;
	char	*line;
	char	*trimmed;

	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (0);
		trimmed = ft_strtrim(line);
		free(line);
		if (trimmed[0] == ';' || trimmed[0] == COMMENT_CHAR || is_name(trimmed)
				|| is_comment(trimmed) || ft_strlen(trimmed) <= 1)
			continue ;
		strip_comments(&trimmed);
		add_instruction_to_list(trimmed, instruct);
	}
	return (1);
}
