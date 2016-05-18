/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:55:28 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:58:52 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s_ptr;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	s_ptr = (unsigned char*)s;
	while (n)
	{
		if (*s_ptr == ch)
			return ((void*)s_ptr);
		s_ptr++;
		n--;
	}
	return (NULL);
}
