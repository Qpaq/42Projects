/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 19:19:59 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/29 12:11:48 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		count_words(char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

int		check_line(char *line)
{
	char	*tmp;

	tmp = line;
	line = ft_strtrim(line);
	if (ft_strlen(tmp) != ft_strlen(line))
		return (-1);
	if (ft_strlen(line) <= 0)
		return (-1);
	if (line[0] == '#')
		return (0);
	if (ft_strchr(line, '-'))
	{
		if (ft_strcount(line, '-') > 1)
			return (-1);
		if (count_words(line, '-') == 2 && !ft_strchr(line, ' '))
			return (2);
	}
	else
	{
		if (count_words(line, ' ') != 3)
			return (-1);
		if (ft_strcount(line, ' ') == 2)
			return (1);
	}
	return (-1);
}

int		check_start_or_end(char **line, int *start, int *end, char **file)
{
	int		ret;

	ret = 1;
	*start = 0;
	*end = 0;
	if (ft_strcmp(*line, "##start") == 0)
	{
		*start = 1;
		ret = get_next_line(0, line);
		if (check_line(*line) != 1)
			return (0);
		*file = ft_strjoin(*file, *line);
		*file = ft_strjoin(*file, "\n");
	}
	if (ft_strcmp(*line, "##end") == 0)
	{
		*end = 1;
		ret = get_next_line(0, line);
		if (check_line(*line) != 1)
			return (0);
		*file = ft_strjoin(*file, *line);
		*file = ft_strjoin(*file, "\n");
	}
	return (ret);
}

void	parse_file(t_rooms **rooms, int start, int end, char **file)
{
	char	*line;

	if (get_next_line(0, &line) == -1)
		return ;
	while (check_line(line) == 1 || check_line(line) == 0)
	{
		*file = ft_strjoin(*file, line);
		*file = ft_strjoin(*file, "\n");
		if (!check_start_or_end(&line, &start, &end, file))
			return ;
		if (line[0] != '#' && (*rooms = add_room(*rooms,
							ft_strsplit(line, ' '), start, end)) == NULL)
			return ;
		if (!get_next_line(0, &line))
			return ;
	}
	while (check_line(line) == 2 || check_line(line) == 0)
	{
		*file = ft_strjoin(*file, line);
		*file = ft_strjoin(*file, "\n");
		if (line[0] != '#' && add_con(*rooms, ft_strsplit(line, '-'), 0) != 2)
			return ;
		if (!get_next_line(0, &line))
			return ;
	}
}
