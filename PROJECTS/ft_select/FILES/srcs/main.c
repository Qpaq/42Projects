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

void	test_capabilities(void)
{
	char	*cm;
	char	*cl;

	cm = tgetstr("cm", NULL);
	cl = tgetstr("cl", NULL);
	/*
	tputs(cm, 1, putchar_select);
	tputs(tgoto(cm, 1, 1), 1, putchar_select);
	*/
}

int		check_capability(char *cap)
{
	if (tgetflag(cap) == 0 && tgetnum(cap) == -1 && tgetstr(cap, NULL) == 0)
		return (0);
	return (1);
}

int		execute_capability(char *cap, int type)
{
	int		res_int;
	char	*res_str;

	if (check_capability(cap) == 0)
		return (0);
	if (type == 1)
	{
		res_int = tgetflag(cap);
		res_str = 0;
	}
	else if (type == 2)
	{
		res_int = tgetnum(cap);
		res_str = 0;
	}
	else if (type == 3)
	{
		res_str = tgetstr(cap, NULL);
		res_int = 0;
	}
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
//	ft_signals();
	get_key();
	test_capabilities();
	restore_terminal();
	return (0);
}
