/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 13:56:51 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 17:59:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

void	ft_display_file(char *av)
{
	int		fd;
	char	file_content;

	if (-1 == (fd = open(av, O_RDONLY)))
		write(2, "Problem opening file\n", 21);
	else
	{
		while (read(fd, &file_content, 1) != 0)
			write(1, &file_content, 1);
		if (-1 == close(fd))
			write(2, "Problem closing file\n", 21);
	}
}
