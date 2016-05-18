/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:18:22 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:35:15 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		length;
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	if ((end = ft_strlen(s) - 1) <= -1)
		return (new = ft_strnew(0));
	while (end > 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	length = end + 1;
	if (!(new = (char*)malloc(length + 1)))
		return (NULL);
	i = 0;
	while (length)
	{
		new[i++] = *s++;
		length--;
	}
	new[i] = '\0';
	return (new);
}
