/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inst_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:20 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 17:57:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*get_inst_label(char **line)
{
	char	*start;
	char	*end;
	int		i;

	start = *line;
	if ((end = ft_strchr(*line, LABEL_CHAR)) == NULL)
		return (NULL);
	i = 0;
	while (*line != end)
	{
		if (ft_strchr(LABEL_CHARS, **line) == NULL)
		{
			*line = start;
			return (NULL);
		}
		(*line)++;
		i++;
	}
	(*line)++;
	return (ft_strsub(start, 0, i));
}

char	*get_inst_name(char **line)
{
	char	*start;
	char	*name;
	int		i;
	t_op	*tab;

	start = *line;
	while (**line && !ft_isalpha(**line))
		(*line)++;
	name = ft_strnew(1);
	i = 0;
	while (**line && ft_isalpha(**line))
	{
		name[i++] = **line;
		name = ft_str_realloc(name, ft_strlen(name) + 1);
		(*line)++;
	}
	if ((tab = return_op_tab(name)))
		return (name);
	*line = start;
	return (NULL);
}

char	**get_inst_args(char *line)
{
	char	**args;
	char	*tmp;
	int		i;

	if (ft_strlen(line) <= 1)
		return (NULL);
	args = ft_strsplit(line, SEPARATOR_CHAR);
	i = 0;
	while (args[i])
	{
		tmp = ft_strtrim(args[i]);
		free(args[i]);
		args[i] = tmp;
		i++;
	}
	return (args);
}

int		get_arg_size(char *arg, t_op *tab)
{
	int		ret;

	ret = 0;
	if (arg[0] == 'r')
		ret = 1;
	else if (arg[0] == DIRECT_CHAR)
		ret = tab->label_size;
	else
		ret = 2;
	return (ret);
}

int		get_inst_size(char **args, t_instruct *current)
{
	int		i;
	int		size;
	t_op	*tab;

	if (args == NULL)
		return (0);
	size = 1;
	if ((tab = return_op_tab(current->instruction)))
		size += tab->o_cod;
	i = 0;
	while (args[i])
	{
		size += get_arg_size(args[i], tab);
		i++;
	}
	return (size);
}
