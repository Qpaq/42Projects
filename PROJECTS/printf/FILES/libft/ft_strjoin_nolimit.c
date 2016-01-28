/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nolimit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 17:04:32 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin_nolimit(char *s1, ...)
{
	char	*new;
	char	*next;
	int		i;
	va_list	args;

	i = 0;
	va_start(args, s1);
	next = s1;
	if (!(new = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (1)
	{
		while (*next)
			new[i++] = *next++;
		next = va_arg(args, char *);
		if (!next)
			break ;
		new = ft_mem_realloc(new, ft_strlen(new) + ft_strlen(next) + 1);
	}
	va_end(args);
	return (new);
}
