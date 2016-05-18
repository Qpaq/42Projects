/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 14:00:40 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/17 14:00:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_comment(char *line, t_header *header, int fd)
{
	int		i;
	char	*start;

	start = ft_strchr(line, '"') + 1;
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		if (*start == '"')
			break ;
		if (*start == '\0')
		{
			header->comment[i++] = '\n';
			get_next_line(fd, &start);
			continue ;
		}
		header->comment[i] = *start;
		i++;
		start++;
	}
	while (i < COMMENT_LENGTH)
	{
		header->comment[i] = '\0';
		i++;
	}
	return (1);
}

static int		get_name(char *line, t_header *header, int fd)
{
	int		i;
	char	*start;

	start = ft_strchr(line, '"') + 1;
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (*start == '"')
			break ;
		if (*start == '\0')
		{
			header->prog_name[i++] = '\n';
			get_next_line(fd, &start);
			continue ;
		}
		header->prog_name[i] = *start;
		i++;
		start++;
	}
	while (i < PROG_NAME_LENGTH)
	{
		header->prog_name[i] = '\0';
		i++;
	}
	return (1);
}

int				is_name(char *line)
{
	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		if (line[ft_strlen(NAME_CMD_STRING)] == ' '
			|| line[ft_strlen(NAME_CMD_STRING)] == '\t')
			return (1);
	}
	return (0);
}

int				is_comment(char *line)
{
	if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		if (line[ft_strlen(COMMENT_CMD_STRING)] == ' ')
			return (1);
		if (line[ft_strlen(COMMENT_CMD_STRING)] == '\t')
			return (1);
	}
	return (0);
}

char	*ft_strtrim_start(char *s)
{
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	return (s);
}

int				get_header(int fd, t_header *header)
{
	int		ret;
	char	*line;
	char	*trimmed;
	int		check;

	check = 0;
	header->magic = COREWAR_EXEC_MAGIC;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return (0);
		trimmed = ft_strtrim_start(line);
		if (is_name(trimmed) && ++check)
			get_name(trimmed, header, fd);
		else if (is_comment(trimmed) && ++check)
			get_comment(trimmed, header, fd);
	}
	if (check != 2)
		error_exit("File has no NAME or COMMENT");
	return (1);
}
