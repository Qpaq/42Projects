/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:11:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/08 12:12:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch_signal(int code)
{
	if (code == SIGINT || code == SIGQUIT || code == SIGCONT || code == SIGKILL)
	{
		reset_settings();
		ft_putendl("exiting");
		exit(0);
	}
	if (code == SIGTSTP)
		ft_putendl("ctrlZ");
}

void	ft_signals(void)
{
	signal(SIGINT, catch_signal);
	signal(SIGQUIT, catch_signal);
	signal(SIGKILL, catch_signal);
	signal(SIGCONT, catch_signal);
	signal(SIGTSTP, catch_signal);
}
