/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:00 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/11 17:11:37 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
}

int			main(int ac, char **av)
{
	t_ls_args		*ls_args;

	// la on stocke toutes les options de notre LS dans une structure
	// et on stocke les repertoires donnés en arguments dans une liste chainées
	if (!(ls_args = (t_ls_args *)malloc(sizeof(t_ls_args))))
		return (0);
	ls_args->authorized_options = "Ralrt"; //ft_strdup("Ralrt");
	ls_args->options = NULL;
	ls_args->dirs = NULL;

	// ici on verifie les arguments donnés et on stocke les repertoires
	// demandés dans un tableau
	check_arguments(ac, av, ls_args);

	// Puis on lance notre LS
	ft_ls(ls_args);
	return (0);
}
