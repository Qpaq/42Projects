/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:07:04 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/28 17:07:06 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list_gnl	*init_list_gnl(int fd)
{
	t_list_gnl *link;

	if (!(link = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	link->fd = fd;
	if (!(link->temp = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	link->next = NULL;
	return (link);
}

static t_list_gnl	*return_current_link(t_list_gnl *head, int fd)
{
	t_list_gnl	*link;

	while (head->next)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	if (head->fd == fd)
		return (head);
	else
	{
		link = init_list_gnl(fd);
		head->next = link;
		return (link);
	}
}

static int			get_line(int fd, t_list_gnl *current_link, char **line)
{
	int			i;
	int			size;

	i = -1;
	size = ft_strlen(current_link->temp) + 1;
	while (size > 0 && ++i >= 0)
	{
		if ((current_link->temp)[i] == '\n')
		{
			*line = ft_strjoin(*line, ft_strndup(current_link->temp, i));
			current_link->temp = &((current_link->temp)[i + 1]);
			return (1);
		}
		if ((current_link->temp)[i] == '\0')
		{
			*line = ft_strjoin(*line, current_link->temp);
			if (!(current_link->temp = ft_strnew(BUFF_SIZE + 1)))
				return (-1);
			size = read(fd, current_link->temp, BUFF_SIZE);
			i = -1;
		}
	}
	return (size);
}

int					get_next_line(int const fd, char **line)
{
	int					ret;
	static t_list_gnl	*head;
	t_list_gnl			*current_link;

	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!head)
	{
		head = init_list_gnl(fd);
		if ((ret = read(fd, head->temp, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (0);
	}
	*line = ft_strnew(1);
	current_link = return_current_link(head, fd);
	ret = get_line(fd, current_link, line);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
