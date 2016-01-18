/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:01:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 16:43:36 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_files_long(t_files *head, char *options,
		int links_column, int size_column)
{
	ft_putchar(head->type);
	ft_putstr(head->permissions);
	ft_putchar(' ');
	pad_with_spaces(head, links_column, 1);
	ft_putnbr(head->links);
	ft_putchar(' ');
	ft_putstr(head->owner);
	ft_putchar(' ');
	ft_putstr(head->group);
	ft_putchar(' ');
	pad_with_spaces(head, size_column, 2);
	ft_putnbr(head->size);
	ft_putchar(' ');
	ft_putstr(head->date);
	ft_putchar(' ');
	if (ft_strchr(options, 'G'))
		add_color(head);
	ft_putstr(head->name);
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void		print_files_short(t_files *head, char *options)
{
	if (ft_strchr(options, 'G'))
		add_color(head);
	ft_putstr(head->name);
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
