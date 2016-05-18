/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:38:32 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 18:49:07 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_prog_size(int fd)
{
	int		size;
	char	buf;
	int		buf2;
	int		i;

	i = 0;
	size = 0;
	while (i < 4)
	{
		read(fd, &buf, 1);
		if (buf < 0)
			buf2 = 256 + buf;
		else
			buf2 = buf;
		size += ft_power(256, 3 - i) * buf2;
		i++;
	}
	if (size > CHAMP_MAX_SIZE)
		return (0);
	return (size);
}

int		check_prog_size(int fd, int size)
{
	int		i;
	char	buf;
	int		ret;

	i = 0;
	while (i < size && (ret = read(fd, &buf, 1)))
	{
		if (ret == -1)
			return (0);
		i++;
	}
	if (i == size)
		return (1);
	return (0);
}

int		check_cor_file(int fd)
{
	int		ret;
	int		size;

	ret = 0;
	ret += read_and_check_magic(fd);
	ret += read_and_check_name(fd);
	if ((size = get_prog_size(fd)) == 0)
		return (0);
	ret += read_and_check_comment(fd);
	ret += check_prog_size(fd, size);
	lseek(fd, 0, SEEK_SET);
	if (ret == 4)
		return (1);
	return (0);
}

void	check_cor_files(int ac, char **av)
{
	int		fd;
	int		i;

	i = 1;
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) != -1)
		{
			if (!check_cor_file(fd))
				ft_error("Error: Invalid file");
			close(fd);
		}
		i++;
	}
}
