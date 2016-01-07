/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 11:45:47 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/13 11:55:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*str;

	size = 0;
	while (src[size] != '\0')
		size++;
	str = (char*)malloc(sizeof(*src) * size);
	while (size >= 0)
	{
		str[size] = src[size];
		size--;
	}
	return (str);
}
