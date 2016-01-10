/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 12:03:16 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/13 14:28:54 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	int		min2;

	if (max <= min)
		return ((void*)0);
	tab = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	min2 = min;
	while (i < (max - min))
	{
		tab[i] = min2;
		i++;
		min2++;
	}
	return (tab);
}
