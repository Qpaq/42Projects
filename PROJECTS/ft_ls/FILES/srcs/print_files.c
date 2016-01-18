/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:01:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 11:45:42 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_color(t_files *file)
{
	if (file->type == 'd' && ft_strcount(file->permissions, 'w') == 3)
		ft_putstr("\033[30;46m");
	else if (file->type == 'd')
		ft_putstr("\033[1;36m");
	else if (file->type == 'l')
		ft_putstr("\033[35m");
	else if (file->type == 'p')
		ft_putstr("\033[33m");
	else if (file->type == 'c')
		ft_putstr("\033[34;43m");
	else if (file->type == 'b')
		ft_putstr("\033[34;46m");
	else if (ft_strchr(file->permissions, 'x'))
		ft_putstr("\033[31m");
}

static int	get_total_size(t_files *head)
{
	t_files	*ptr;
	int		result;

	ptr = head;
	result = 0;
	while (ptr)
	{
		result += ptr->blocks;
		ptr = ptr->next;
	}
	return (result);
}

void		print_files_long(t_files *head, char *options)
{
	int		links_column;
	int		size_column;

	links_column = get_length_column(head, 1);
	size_column = get_length_column(head, 2);
	while (head)
	{
		if (ft_strchr(options, 's'))
		{
			ft_putnbr(head->blocks);
			ft_putchar(' ');
		}
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
		if (ft_strchr(options, 'G'))
			add_color(head);
		ft_putstr(head->name);
		ft_putstr("\033[0m");
		ft_putchar('\n');
		head = head->next;
	}
}

void		print_files_short(t_files *head, char *options)
{
	while (head)
	{
		if (ft_strchr(options, 's'))
		{
			ft_putnbr(head->blocks);
			ft_putchar(' ');
		}
		if (ft_strchr(options, 'G'))
			add_color(head);
		ft_putstr(head->name);
		ft_putstr("\033[0m");
		ft_putchar('\n');
		head = head->next;
	}
}

void		print_dir(t_files *head, char *dir_name, t_ls_args *args)
{
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args->options, 'l'))
	{
		ft_putstr("total ");
		ft_putnbr(get_total_size(head));
		ft_putchar('\n');
		print_files_long(head, args->options);
	}
	else
		print_files_short(head, args->options);
}

void	print_file(t_files *file, t_ls_args *args)
{
	if (ft_strchr(args->options, 'l'))
		print_files_long(file, args->options);
	else
		print_files_short(file, args->options);
}
