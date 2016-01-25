/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:54:53 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 16:42:28 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *message, int time)
{
	if (time == 1)
	{
		ft_putstr("ft_ls: ");
		perror(message);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(message);
		ft_putendl(":");
		ft_putstr("ft_ls: ");
		perror(message);
	}
}

void	error_message(char *message, int terminate)
{
	ft_putcolor("ERROR: ", "red");
	perror(message);
	if (terminate)
		exit(0);
}
