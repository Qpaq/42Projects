/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:12:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/09 11:24:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putchar_select(int c)
{
	int		fd;

	fd = open(ttyname(0), O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (1);
}

int		check_capability(char *cap)
{
	if (tgetflag(cap) == 0 && tgetnum(cap) == -1 && tgetstr(cap, NULL) == 0)
		return (0);
	return (1);
}

int		main(void)
{
	char			*term_name;

	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putendl("Cannot find environment variable TERM");
		return (-1);
	}
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (init_raw_mode() == -1)
		return (-1);
	ft_signals();
	ft_putchar('o');
	get_key();
	restore_terminal();
	return (0);
}
