/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:13 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 10:44:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	store_requested_dir(char *dir_name, t_ls_args *ls_args)
{
	t_files			*new_dir;
	t_files			*head;

	head = ls_args->dirs;
	if (!(new_dir = get_file_info(dir_name)))
		return (0);
	/*
	if (new_dir->type != 'd')
	{
		print_files(new_dir, new_dir->name, ls_args);
		return (1);
	}
	*/
	if (!(ls_args->dirs))
		ls_args->dirs = new_dir;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_dir;
	}
	return (1);
}

void			check_arguments(int ac, char **av, t_ls_args *ls_args)
{
	int			i;
	char		*args_list;
	int			nb_of_dirs;

	i = 0;
	args_list = ft_strnew(2);
	nb_of_dirs = 0;
	while (++i < ac && av[i][0] == '-' && is_option(&av[i][1], ls_args))
	{
		args_list = ft_mem_realloc(args_list, ft_strlen(args_list) + ft_strlen(av[i]));
		args_list = ft_strcat(args_list, &av[i][1]);
	}
	if (i == ac)
		store_requested_dir(".", ls_args);
	while (i < ac)
	{
		nb_of_dirs++;
		if (!store_requested_dir(av[i], ls_args))
			print_error(av[i], 1);
		i++;
	}
	ls_args->options = ft_strdup(args_list);
	ft_memdel((void **)&args_list);
}
