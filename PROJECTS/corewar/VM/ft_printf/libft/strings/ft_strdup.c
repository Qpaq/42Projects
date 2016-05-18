/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:37:29 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:36:41 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*str;

	length = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(*s1) * (length + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
