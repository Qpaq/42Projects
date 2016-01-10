/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 14:42:51 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 13:01:06 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		min2;

	if (max <= min)
		*range = NULL;
	*range = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	min2 = min;
	while (i < (max - min))
	{
		*(*range + i) = min2;
		i++;
		min2++;
	}
	return (max - min);
}
