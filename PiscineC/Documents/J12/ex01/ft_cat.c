/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 13:56:51 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/21 12:43:34 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

void	ft_cat(int ac, char **av)
{
	int		fd;
	char	file_content;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (-1 == (fd = open(av[i], O_RDONLY)))
			write(2, "Problem opening file\n", 21);
		else
		{
			while (0 != read(fd, &file_content, 1))
					write(1, &file_content, 1);
			if (-1 == close(fd))
				write(2, "Problem closing file\n", 21);
		}
		i++;
	}
}
