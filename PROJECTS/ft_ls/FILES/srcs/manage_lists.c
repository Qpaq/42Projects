/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:25:48 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 15:54:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lst_add_end(t_files **head, t_files *new)
{
	t_files		*tmp;

	if (!(*head))
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	lst_insert_after(t_files *target, char *new)
{
	t_files	*new_dir;

	new_dir = (t_files *)ft_memalloc(sizeof(t_files));
	new_dir->name = ft_strdup(new);
	new_dir->next = target->next;
	target->next = new_dir;
}

t_files	*sort_alphabetical(t_files *head)
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
			if (ptr == head)
				head = ptr->next;
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

t_files	*sort_by_time(t_files *head)
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
			if (ptr == head)
				head = ptr->next;
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

t_files	*reverse_list(t_files *head)
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

t_files	*sort_from_options(t_files *head, char *options)
{
	head = sort_alphabetical(head);
	if (ft_strchr(options, 't'))
		head = sort_by_time(head);
	if (ft_strchr(options, 'r'))
		head = reverse_list(head);
	return (head);
}
