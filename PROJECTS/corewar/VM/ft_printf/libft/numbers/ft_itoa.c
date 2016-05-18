/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:59 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:58:21 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		length;
	char	*result;
	int		i;
	long	sign;
	long	nb;

	nb = n;
	length = 1;
	if ((sign = nb) < 0)
		nb = -nb;
	while (ft_power_long(10, length) < nb)
		length++;
	if (!(result = (char*)malloc(length + 1)))
		return (NULL);
	i = 1;
	result[0] = (nb % 10) + 48;
	while ((nb /= 10) > 0)
		result[i++] = (nb % 10) + 48;
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
