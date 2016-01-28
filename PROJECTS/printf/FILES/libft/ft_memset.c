/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 17:02:38 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int src, size_t len)
{
	unsigned char	*ptr;

	ptr = str;
	while (len-- > 0)
		*ptr++ = (unsigned char)src;
	return (str);
}
