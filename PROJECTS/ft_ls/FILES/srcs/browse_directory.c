/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/11 19:27:39 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_infos	*read_directory(t_dir_infos current_dir, t_ls_args *args)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_file_infos	*current_file;
	t_file_infos	*head_list;

	head_list = NULL;
	if (!(dirp = opendir(current_dir->name)))
		return (NULL);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin("/", dir_entry->d_name);
		full_name = ft_strjoin(current_dir->name, full_name);
		if (!head_list)
		{
			head_list = get_file_info(full_name);
			current_file = head_list;
			
			/*
			if (head_list->type == 'd')
				ft_lstinsert_after(args->dirs, current_dir)
			*/
			current_file->name = ft_strdup(dir_entry->d_name);
		}
		else
		{
			current_file->next = get_file_info(full_name);
			current_file = current_file->next;
			current_file->name = ft_strdup(dir_entry->d_name);
		}
	}
	closedir(dirp);
	return (head_list);
}

int				browse_directories(t_ls_args *args)
{
	t_dir_info		*current_dir;
	t_file_infos	*files_list;

	current_dir = args->dirs;
	while (current_dir)
	{
		/*
		modifier le prototype de read_directory()
		*/
		if ((files_list = read_directory(current_dir, args)))
		{
			if (ft_strchr(args->options, 'l'))
				print_dir_long(files_list, current_dir->name);
			else
				print_dir_short(files_list, current_dir->name);
		}
		current_dir = current_dir->next;
		if (current_dir)
			ft_putchar('\n');
	}
	return (1);
}
