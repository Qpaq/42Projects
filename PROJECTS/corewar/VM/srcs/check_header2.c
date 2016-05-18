/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:39:06 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:39:07 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_and_check_magic(int fd)
{
	unsigned int	magic;
	char			buf;
	unsigned int	buf2;
	int				i;

	i = 0;
	magic = 0;
	while (i < 4)
	{
		read(fd, &buf, 1);
		if (buf < 0)
			buf2 = 256 + buf;
		else
			buf2 = buf;
		magic += ft_power(256, 3 - i) * buf2;
		i++;
	}
	if (magic == COREWAR_EXEC_MAGIC)
		return (1);
	return (0);
}

int		read_and_check_name(int fd)
{
	int		i;
	char	buf;
	int		ended;

	ended = 0;
	i = 0;
	while (i < PROG_NAME_LENGTH + 4)
	{
		read(fd, &buf, 1);
		if ((buf == 0 && ended == 0) || i == PROG_NAME_LENGTH)
			ended = 1;
		if (ended && buf != 0)
			return (0);
		i++;
	}
	return (1);
}

int		read_and_check_comment(int fd)
{
	int		i;
	char	buf;
	int		ended;

	ended = 0;
	i = 0;
	while (i < COMMENT_LENGTH + 4)
	{
		read(fd, &buf, 1);
		if ((buf == 0 && ended == 0) || i == COMMENT_LENGTH)
			ended = 1;
		if (ended && buf != 0)
			return (0);
		i++;
	}
	return (1);
}
