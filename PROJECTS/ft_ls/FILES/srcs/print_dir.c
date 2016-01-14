/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:42:00 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 10:34:17 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_dir_long(t_files *head, char *name)
{
	ft_putstr(name);
	ft_putendl(":");
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

void	print_dir_short(t_files *head, char *name)
{
	ft_putstr(name);
	ft_putendl(":");
	while (head)
	{
		ft_putstr(head->name);
		ft_putchar('\n');
		head = head->next;
	}
}

void	print_files(t_files *head, char *name, t_ls_args *args)
{
	if (ft_strchr(args->options, 'l'))
		print_dir_long(head, name);
	else
		print_dir_short(head, name);
}
