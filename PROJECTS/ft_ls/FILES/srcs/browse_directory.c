/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/11 16:57:48 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_infos	*read_directory(char *dir_name, t_ls_args *args)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_file_infos	*current_file;
	t_file_infos	*head_list;

	head_list = NULL;
	dirp = opendir(dir_name);
	ft_putstr(dir_name);
	ft_putendl(":");
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin("/", dir_entry->d_name);
		full_name = ft_strjoin(dir_name, full_name);
		if (!head_list)
		{
			head_list = get_file_info(full_name);
			current_file = head_list;
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

int		browse_directories(t_ls_args *args)
{
	t_dir_info		*current_dir;
	t_file_infos	*files_list;

	current_dir = args->dirs;
	while (current_dir)
	{
		files_list = read_directory(current_dir->name, args);
		if (ft_strchr(args->options, 'l'))
			print_dir_long(files_list);
		else
			print_dir_short(files_list);
		current_dir = current_dir->next;
		if (current_dir)
			ft_putchar('\n');
	}
	return (1);
}
