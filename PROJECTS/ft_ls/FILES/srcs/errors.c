/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:54:53 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 09:14:07 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* "time" permet de savoir quand est ce qu'on recoit l'erreur.
 * si c'est au debut (lorsqu'on verifie les arguments : 1,
 * ou si c'est pendant le deroulement du programme : 2
*/
void	print_error(char *message, int time)
{
	if (time == 1)
	{
		ft_putstr("ls: ");
		perror(message);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(message);
		ft_putendl(":");
		ft_putstr("ls: ");
		perror(message);
	}
}

int		is_option(char *arg, t_ls_args *ls_args)
{
	while (*arg)
	{
		if (!ft_strchr(ls_args->authorized_options, *arg) || !ft_isalnum(*arg))
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			ft_putstr("usage: ls [-");
			ft_putstr(ls_args->authorized_options);
			ft_putendl("] [file ...]");
			exit(0);
		}
		arg++;
	}
	return (1);
}
