/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:34:22 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 19:15:21 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_power_for_ltoa(unsigned long nb, long power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * ft_power_for_ltoa(nb, power - 1));
}

char					*ft_ltoa(long nb)
{
	int		length;
	char	*result;
	int		i;
	long	sign;

	if (nb == LONG_MIN)
		return ("-9223372036854775808");
	length = 1;
	if ((sign = nb) < 0)
		nb = -nb;
	while (ft_power_for_ltoa(10, length) < (unsigned long)nb)
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
