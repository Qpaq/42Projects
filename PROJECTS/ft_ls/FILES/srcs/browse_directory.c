/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/28 10:59:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// ON CHECK dans cette fonction les options -a -l
// et on print en conséquence
void	print_directory(t_file_infos *head)
{
	while (head)
	{
		ft_putchar(head->type);
		ft_putstr(head->permissions);
		ft_putchar(' ');
		ft_putnbr(head->links);
		ft_putchar('\t');
		ft_putstr(head->owner);
		ft_putchar(' ');
		ft_putstr(head->group);
		ft_putchar(' ');
		ft_putnbr(head->size);
		ft_putchar('\t');
		ft_putstr(head->date);
		ft_putchar(' ');
		ft_putendl(head->name);
		head = head->next;
	}
}

void	read_directory(char *dir_name)
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
		full_name = ft_strjoin("/", dir_entry->d_name);
		full_name = ft_strjoin(dir_name, full_name);
		if (!head_list)
		{
			head_list = get_file_info(full_name);
			current_file = head_list;
		}
		else
		{
			current_file->next = get_file_info(full_name);
			current_file = current_file->next;
		}
	}
	print_directory(head_list);
	closedir(dirp);
}

int		browse_directories(t_ls_args *args)
{
	t_dir_info	*current_dir;

	current_dir = args->dirs;
	if (current_dir == NULL)
		read_directory(".");
	else
	{
		while (current_dir)
		{
			read_directory(current_dir->name);
			current_dir = current_dir->next;
		}
	}
	return (1);
}
