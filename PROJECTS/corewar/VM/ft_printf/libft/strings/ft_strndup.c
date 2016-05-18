/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:14:45 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:35:48 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*str;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	if (n < length)
		length = n;
	if (!(str = (char*)malloc(length + 1)))
		return (NULL);
	ft_strncpy(str, s1, length);
	return (str);
}
