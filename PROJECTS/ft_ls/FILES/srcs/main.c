/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:00 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/13 16:55:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_everything(t_ls_args *args)
{
	t_dir_info	*dir;
	t_dir_info	*next;

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
	t_dir_info	*new_dir;

	if (args->dirs == NULL)
	{
		new_dir = (t_dir_info *)malloc(sizeof(t_dir_info));
		new_dir->name = ".";
		new_dir->next = NULL;
		args->dirs = new_dir;
	}
	browse_directories(args);
	free_everything(args);
}

int			main(int ac, char **av)
{
	t_ls_args		*ls_args;

	// la on stocke toutes les options de notre LS dans une structure
	// et on stocke les repertoires donnés en arguments dans une liste chainées
	if (!(ls_args = (t_ls_args *)ft_memalloc(sizeof(t_ls_args))))
		return (0);
	ls_args->authorized_options = ft_strdup("Ralrt");
//	ls_args->options = NULL;
//	ls_args->dirs = NULL;

	// ici on verifie les arguments donnés et on stocke les repertoires
	// demandés dans un tableau
	check_arguments(ac, av, ls_args);

	// Puis on lance notre LS
	ft_ls(ls_args);
	return (0);
}
