/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:32:03 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 12:32:07 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_length_column(t_files *head, char field)
{
	t_files	*ptr;
	int		largest;
	int		tmp;

	ptr = head;
	largest = 0;
	while (ptr)
	{
		if (field == 1)
			tmp = ptr->links;
		else if (field == 2)
			tmp = ptr->size;
		if ((tmp = ft_strlen(ft_itoa(tmp))) > largest)
			largest = tmp;
		ptr = ptr->next;
	}
	return (largest);
}

void	pad_with_spaces(t_files *file, int size, char field)
{
	int		tmp;

	if (field == 1)
		tmp = ft_strlen(ft_itoa(file->links));
	else
		tmp = ft_strlen(ft_itoa(file->size));
	while (tmp < size)
	{
		ft_putchar(' ');
		tmp++;
	}
}

int		get_total_size(t_files *head)
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

void	add_color(t_files *file)
{
	if (file->type == 'd' && ft_strcount(file->permissions, 'w') == 3)
		ft_putstr("\033[30;43m");
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
