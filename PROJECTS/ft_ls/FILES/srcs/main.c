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

void		free_one(t_files *head)
{
	if (head)
	{
		if (head->permissions)
			free(head->permissions);
	//	if (head->owner)
	//		free(head->owner);
	//	if (head->group)
	//		free(head->group);
		if (head->date)
			free(head->date);
		if (head->name)
			free(head->name);
		if (head->parent_dir)
			free(head->parent_dir);
		free(head);
	}
}

void		free_list(t_files *head)
{
	t_files	*next;

	while (head)
	{
		next = head->next;
		if (head->permissions)
			free(head->permissions);
	//	if (head->owner)
	//		free(head->owner);
	//	if (head->group)
	//		free(head->group);
		if (head->date)
			free(head->date);
		if (head->name)
			free(head->name);
		if (head->parent_dir)
			free(head->parent_dir);
		free(head);
		head = next;
	}
}

void		free_everything(t_ls_args *args)
{
	free(args->authorized_options);
	free(args->options);
//	free_list(args->dirs);
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
