/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:15 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 11:29:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *str)
{
	char	*lowered;
	int		i;

	lowered = (char *)ft_memalloc(ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			lowered[i] = str[i] + 32;
		else
			lowered[i] = str[i];
		i++;
	}
	return (lowered);
}
