/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:57:45 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:36:19 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = 0;
	if (dst && src && size > 0)
	{
		while (dst[i] && i < size)
			i++;
		len_dst = i;
		while (src[i - len_dst] && i < size - 1)
		{
			dst[i] = src[i - len_dst];
			i++;
		}
		if (i < size)
			dst[i] = 0;
	}
	return (len_dst + ft_strlen(src));
}
