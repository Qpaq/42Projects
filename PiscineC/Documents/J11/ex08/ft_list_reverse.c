/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 19:34:46 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/20 20:26:35 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*temp;
	t_list	*previous;

	previous = *begin_list;
	current = previous->next;
	previous->next = NULL;
	while (current->next)
	{
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}
}
