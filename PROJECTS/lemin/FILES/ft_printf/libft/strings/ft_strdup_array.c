/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:02:42 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 20:02:43 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strdup_array(char **array)
{
	int			i;
	char		**new;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	if (!(new = (char **)malloc((sizeof(*new) * i) + 1)))
		return (NULL);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
