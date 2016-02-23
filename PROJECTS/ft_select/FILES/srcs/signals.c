/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:11:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/10 09:45:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch_signal(int code)
{
	if (code == SIGINT || code == SIGQUIT || code == SIGKILL)
	{
		restore_terminal();
		ft_putendl("exiting");
		exit(0);
	}
	if (code == SIGTSTP)
	{
		restore_terminal();
		ft_putendl("ctrlZ");
		exit(0);
	}
	if (code == SIGCONT)
	{
		init_raw_mode();
		ft_putendl("returning with fg");
	}
	if (code == SIGSEGV)
	{
		restore_terminal();
		ft_putendl("Attention ! SEGFAULT");
		exit(0);
	}
}

void	check_window_size(int code)
{
	int		width;
	int		height;
	struct winsize	max_size;

	ft_printf("%d %d", max_size.ws_col, max_size.ws_row);

	if (code == SIGWINCH)
	{
		width = tgetnum("co");
		height = tgetnum("li");
		ft_printf("cols: %d, lines: %d\n", width, height);
	}
}

void	ft_signals(void)
{
	signal(SIGINT, catch_signal);
	signal(SIGQUIT, catch_signal);
	signal(SIGKILL, catch_signal);
	signal(SIGCONT, catch_signal);
	signal(SIGWINCH, check_window_size);
//	signal(SIGTSTP, catch_signal);
//	signal(SIGSEGV, catch_signal);
}
