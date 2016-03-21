/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:11:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:24:27 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch_signal(int code)
{
	if (code == SIGINT || code == SIGQUIT || code == SIGKILL)
	{
		restore_terminal();
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
		ft_putendl("Wrong action\nExiting program...\n");
		exit(0);
	}
}

void	check_window_size(int code)
{
	struct winsize	win_size;

	if (code == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &win_size);
		ft_printf("rows: %d / cols: %d\n", win_size.ws_row, win_size.ws_col);
	}
}

void	ft_signals(void)
{
	signal(SIGINT, catch_signal);
	signal(SIGQUIT, catch_signal);
	signal(SIGKILL, catch_signal);
	signal(SIGCONT, catch_signal);
	signal(SIGWINCH, check_window_size);
	signal(SIGTSTP, catch_signal);
	signal(SIGSEGV, catch_signal);
}
