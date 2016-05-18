/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 09:09:39 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:36:46 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_array(char ***as)
{
	char	**tab;

	tab = *as;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free(*as);
	*as = NULL;
}
