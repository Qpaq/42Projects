/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:08:08 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:35:52 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	dst_ptr = dst;
	while (*src && n > 0)
	{
		n--;
		*dst_ptr++ = *src++;
	}
	*dst_ptr = 0;
	while (n-- > 0)
		*dst_ptr++ = 0;
	return (dst);
}
