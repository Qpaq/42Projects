/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:24:49 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 20:27:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*sort_by_name(t_files *head)
{
	t_files		*ptr;
	t_files		*previous;
	t_files		*temp;

	ptr = head;
	previous = ptr;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->name, (ptr->next)->name) > 0)
		{
			head = (ptr == head) ? ptr->next : head;
			previous->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			previous = ptr;
		}
		else
		{
			previous = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*sort_by_date(t_files *head)
{
	t_files		*ptr;
	t_files		*previous;
	t_files		*temp;

	ptr = head;
	previous = ptr;
	while (ptr->next)
	{
		if (ptr->timestamp < (ptr->next)->timestamp)
		{
			head = (ptr == head) ? ptr->next : head;
			previous->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			previous = ptr;
		}
		else
		{
			previous = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*sort_by_size(t_files *head)
{
	t_files		*ptr;
	t_files		*previous;
	t_files		*temp;

	ptr = head;
	previous = ptr;
	while (ptr->next)
	{
		if (ptr->size < (ptr->next)->size)
		{
			head = (ptr == head) ? ptr->next : head;
			previous->next = ptr->next;
			temp = (ptr->next)->next;
			(ptr->next)->next = ptr;
			ptr->next = temp;
			ptr = head;
			previous = ptr;
		}
		else
		{
			previous = ptr;
			ptr = ptr->next;
		}
	}
	return (head);
}

t_files		*reverse_list(t_files *head)
{
	t_files		*ptr;
	t_files		*previous;
	t_files		*temp;

	ptr = head->next;
	previous = head;
	while (head->next)
		head = head->next;
	previous->next = NULL;
	while (ptr)
	{
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = temp;
	}
	return (head);
}

t_files		*sort_from_options(t_files *head, char *options, char by_name)
{
	if (head && !ft_strchr(options, 'f'))
	{
		if (by_name)
			head = sort_by_name(head);
		if (ft_strchr(options, 't'))
			head = sort_by_date(head);
		else if (ft_strchr(options, 'S'))
			head = sort_by_size(head);
		if (ft_strchr(options, 'r'))
			head = reverse_list(head);
	}
	return (head);
}
