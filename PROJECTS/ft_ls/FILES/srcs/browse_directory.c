/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 11:28:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files			*get_file_info(char *file_name)
{
	struct stat	buf;
	t_files		*file;

	if (!(file = (t_files *)ft_memalloc(sizeof(t_files))))
		return (NULL);
	if (lstat(file_name, &buf) == -1)
		return (NULL);
	/*
	if (file_type(buf.st_mode) != 'l')
	{
		if (stat(file_name, &buf) == -1)
			return (NULL);
	}
	*/
	file->name = ft_strdup(file_name);
	file->type = file_type(buf.st_mode);
	file->permissions = file_permissions(buf.st_mode);
	file->links = buf.st_nlink;
	file->owner = get_owner(buf);
	file->group = get_group(buf);
	file->size = buf.st_size;
	file->blocks = buf.st_blocks;
	file->date = get_date(buf);
	file->timestamp = buf.st_mtimespec.tv_sec;
	file->next = NULL;
	return (file);
}

int				read_directory(t_files *current_dir, t_ls_args *args, t_files **head)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_files			*tmp;
	t_files			*recursive;

	recursive = NULL;
	if (!(dirp = opendir(current_dir->name)))
		return (0);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin_nolimit(0, current_dir->name, "/", dir_entry->d_name, NULL);
		tmp = get_file_info(full_name);
		if (ft_strchr(args->options, 'R'))
		{
			if (tmp->type == 'd' && ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
				lst_add_end(&recursive, lst_copy_link(tmp));
		}
		tmp->name = ft_strdup(dir_entry->d_name);
		tmp->parent_dir = ft_strdup(current_dir->name);
		lst_add_end(head, tmp);
		ft_memdel((void **)&full_name);
	}
	if (recursive)
	{
		recursive = sort_from_options(recursive, args->options);
		concat_list(current_dir, recursive);
	}
	closedir(dirp);
	return (1);
}

int				browse_directories(t_ls_args *args)
{
	t_files		*files_list;
	t_files		*tmp;

	while (args->dirs)
	{
		files_list = NULL;
		if (read_directory(args->dirs, args, &files_list))
		{
			files_list = sort_from_options(files_list, args->options);
			print_dir(files_list, (args->dirs)->name, args);
		}
		else
			print_error((args->dirs)->name, 2);
		free_list(files_list);
		tmp = args->dirs;
		args->dirs = (args->dirs)->next;
		if (args->dirs)
			ft_putchar('\n');
	}
	return (1);
}
