/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:01:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 20:28:50 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_file_size(t_files *file, int size_col)
{
	if (file->type == 'b' || file->type == 'c')
	{
		ft_putnbr((int)major(file->device));
		ft_putstr(", ");
		ft_putnbr((int)minor(file->device));
	}
	else
	{
		pad_with_spaces(file, size_col, 2);
		ft_putnbr(file->size);
	}
}

void		print_files_long(t_files *file, char *options,
		int links_column, int size_column)
{
	ft_putchar(file->type);
	ft_putstr(file->permissions);
	ft_putchar(' ');
	pad_with_spaces(file, links_column, 1);
	ft_putnbr(file->links);
	ft_putchar(' ');
	if (!ft_strchr(options, 'g'))
	{
		ft_putstr(file->owner);
		ft_putchar(' ');
	}
	ft_putstr(file->group);
	ft_putchar(' ');
	print_file_size(file, size_column);
	ft_putchar(' ');
	ft_putstr(file->date);
	ft_putchar(' ');
	if (ft_strchr(options, 'G'))
		add_color(file);
	ft_putstr(file->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void		print_files_short(t_files *file, char *options)
{
	if (ft_strchr(options, 'G'))
		add_color(file);
	ft_putstr(file->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void		print_dir(t_files *head, char *dir_name, t_ls_args *args)
{
	int		links_column;
	int		size_column;

	links_column = get_length_column(head, 1);
	size_column = get_length_column(head, 2);
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args->options, 'l') && head)
	{
		ft_putstr("total ");
		ft_putnbr(get_total_size(head));
		ft_putchar('\n');
	}
	while (head)
	{
		if (ft_strchr(args->options, 's'))
		{
			ft_putnbr(head->blocks);
			ft_putchar(' ');
		}
		print_file(head, args, links_column, size_column);
		head = head->next;
	}
}

void		print_file(t_files *file, t_ls_args *args,
		int links_col, int size_col)
{
	if (ft_strchr(args->options, 'l'))
		print_files_long(file, args->options, links_col, size_col);
	else
		print_files_short(file, args->options);
}
