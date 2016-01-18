/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_columns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:25:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 10:26:23 by dtedgui          ###   ########.fr       */
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
