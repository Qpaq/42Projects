/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 16:00:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		read_directory(t_files *current_dir, t_ls_args *args, t_files **head)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_files			*tmp;
	t_files			*recursive_list;

	recursive_list = NULL;
	if (!(dirp = opendir(current_dir->name)))
		return (0);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin("/", dir_entry->d_name);
		full_name = ft_strjoin(current_dir->name, full_name);
		tmp = get_file_info(full_name);
		tmp->name = ft_strdup(dir_entry->d_name);
		tmp->parent_dir = ft_strdup(current_dir->name);
		if (ft_strchr(args->options, 'R'))
		{
			if (tmp->type == 'd' && ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
				lst_add_end(&recursive_list, tmp);
			//	lst_insert_after(current_dir, full_name);
		}
		lst_add_end(head, tmp);
	}
//	if (ft_strchr(args->options, 'R'))
//		lst_insert_after(current_dir, recursive_list);
	closedir(dirp);
	return (1);
}

int		browse_directories(t_ls_args *args)
{
	t_files		*current_dir;
	t_files		*files_list;

	current_dir = args->dirs;
	while (current_dir)
	{
		files_list = NULL;
		if (read_directory(current_dir, args, &files_list))
			print_dir(files_list, current_dir->name, args);
		else
			print_error(current_dir->name, 2);
		current_dir = current_dir->next;
		if (current_dir)
			ft_putchar('\n');
	}
	return (1);
}
