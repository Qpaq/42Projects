/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 19:44:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files			*get_file_info(char *file_name, char is_link)
{
	struct stat	buf;
	t_files		*file;

	file = (t_files *)ft_memalloc(sizeof(t_files));
	if (lstat(file_name, &buf) == -1)
		return (NULL);
	if (is_link)
	{
		if (stat(file_name, &buf) == -1)
			return (NULL);
	}
	file->device = buf.st_rdev;
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

int				read_directory(t_files *current_dir,
		t_ls_args *args, t_files **head, t_files **recursive)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_files			*tmp;

	if (!(dirp = opendir(current_dir->name)))
		return (0);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin_nolimit(0, current_dir->name,
				"/", dir_entry->d_name, NULL);
		if (!(tmp = get_file_info(full_name, 0)))
			return (0);
		if (ft_strchr(args->options, 'R') && tmp->type == 'd' &&
	ft_strcmp(dir_entry->d_name, ".") && ft_strcmp(dir_entry->d_name, ".."))
			lst_add_end(recursive, lst_copy_link(tmp));
		tmp->name = ft_strdup(dir_entry->d_name);
		tmp->parent_dir = ft_strdup(current_dir->name);
		lst_add_end(head, tmp);
		ft_memdel((void **)&full_name);
	}
	closedir(dirp);
	return (1);
}

void			browse_directories(t_ls_args *args)
{
	t_files		*files_list;
	t_files		*recursive;
	t_files		*cur_dir;

	cur_dir = args->dirs;
	while (cur_dir)
	{
		files_list = NULL;
		recursive = NULL;
		if (read_directory(cur_dir, args, &files_list, &recursive))
		{
			files_list = sort_from_options(files_list, args->options, 1);
			print_dir(files_list, (cur_dir)->name, args);
		}
		else
			print_error((cur_dir)->name, 2);
		free_list(files_list);
		if (recursive)
		{
			recursive = sort_from_options(recursive, args->options, 1);
			concat_list(cur_dir, recursive);
		}
		if ((cur_dir = cur_dir->next))
			ft_putchar('\n');
	}
}
