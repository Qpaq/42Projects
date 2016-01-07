/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:43:06 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/04 20:44:46 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_mem_realloc(char *old, size_t size)
{
	char	*new;

	new = ft_strnew(size);
	ft_memcpy(new, old, ft_strlen(old));
	free(old);
	return (new);
}
