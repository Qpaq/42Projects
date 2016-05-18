/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:06:46 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:59:22 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconcat(t_list *lnk_first_list, t_list *head_second_list)
{
	if (lnk_first_list && head_second_list)
	{
		while (lnk_first_list->next)
			lnk_first_list = lnk_first_list->next;
		lnk_first_list->next = head_second_list;
	}
}
