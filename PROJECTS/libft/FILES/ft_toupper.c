/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:32 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 09:51:54 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_toupper(char *str)
{
	char	*uppered;
	int		i;

	uppered = (char *)ft_memalloc(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			uppered[i] = str[i] - 32;
		else
			uppered[i] = str[i];
		i++;
	}
	return (uppered);
}
