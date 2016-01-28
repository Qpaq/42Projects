/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 17:02:11 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mem_realloc(char *old, size_t size)
{
	char	*new;

	new = ft_strnew(size);
	ft_memcpy(new, old, ft_strlen(old));
	ft_memdel((void **)&old);
	return (new);
}
