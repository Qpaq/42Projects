/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:01:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 15:16:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_color(t_files *file)
{
	if (file->type == 'd')
		ft_putstr("\033[36m");
	else if (file->type == 'l')
		ft_putstr("\033[35m");
	else if (file->permissions[2] == 'x')
		ft_putstr("\033[31m");
}

void	print_files_long(t_files *file)
{
	ft_putchar(file->type);
	ft_putstr(file->permissions);
	ft_putchar(' ');
	ft_putnbr(file->links);
	ft_putchar('\t');
	ft_putstr(file->owner);
	ft_putchar(' ');
	ft_putstr(file->group);
	ft_putchar(' ');
	ft_putnbr(file->size);
	ft_putchar('\t');
	ft_putstr(file->date);
	ft_putchar(' ');
	add_color(file);
	ft_putendl(file->name);
	ft_putstr("\033[0m");
}

void	print_files_short(t_files *file)
{
	add_color(file);
	ft_putstr(file->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	print_dir(t_files *head, char *dir_name, t_ls_args *args)
{
	ft_putstr(dir_name);
	ft_putendl(":");
	while (head)
	{
		if (ft_strchr(args->options, 'l'))
			print_files_long(head);
		else
			print_files_short(head);
		head = head->next;
	}
}

void	print_file(t_files *file, t_ls_args *args)
{
	if (ft_strchr(args->options, 'l'))
		print_files_long(file);
	else
		print_files_short(file);
}
