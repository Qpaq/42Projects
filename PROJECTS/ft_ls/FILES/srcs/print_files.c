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
		ft_putstr("\033[1;36m");
	else if (file->type == 'l')
		ft_putstr("\033[35m");
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

void		print_files_long(t_files *file, char *options)
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
	if (ft_strchr(options, 'G'))
		add_color(file);
	ft_putendl(file->name);
	ft_putstr("\033[0m");
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
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args->options, 'l'))
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
		if (ft_strchr(args->options, 'l'))
			print_files_long(head, args->options);
		else
			print_files_short(head, args->options);
		head = head->next;
	}
}

void	print_file(t_files *file, t_ls_args *args)
{
	if (ft_strchr(args->options, 'l'))
		print_files_long(file, args->options);
	else
		print_files_short(file, args->options);
}
