/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:00 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 11:15:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_everything(t_ls_args *args)
{
	t_files		*dir;
	t_files		*next;

	free(args->authorized_options);
	free(args->options);
	dir = args->dirs;
	while (dir)
	{
		next = dir->next;
		free(dir);
		dir = next;
	}
}

void		ft_ls(t_ls_args *args)
{
	browse_directories(args);
	free_everything(args);
}

int			main(int ac, char **av)
{
	t_ls_args		*ls_args;

	if (!(ls_args = (t_ls_args *)ft_memalloc(sizeof(t_ls_args))))
		return (0);
	ls_args->authorized_options = ft_strdup("Ralrt");
	check_arguments(ac, av, ls_args);
	ft_ls(ls_args);
	return (0);
}
