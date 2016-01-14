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

void	print_files_long(t_files *head)
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

void	print_files_short(t_files *head)
{
	while (head)
	{
		ft_putstr(head->name);
		ft_putchar('\n');
		head = head->next;
	}
}

void	print_dir(t_files *head, char *dir_name, t_ls_args *args)
{
	ft_putstr(dir_name);
	ft_putendl(":");
	if (ft_strchr(args->options, 'l'))
		print_files_long(head);
	else
		print_files_short(head);
}

void	print_file(t_files *file, t_ls_args *args)
{
	if (ft_strchr(args->options, 'l'))
		print_files_long(file);
	else
		print_files_short(file);
}
