/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:24:35 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 13:47:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = 0;
	i = 0;
	while (str[++length]);
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	str[length] = '\0';
	return (str);
}

int		ft_power(int nb, int pow)
{
	if (pow == 0)
		return (1);
	return (nb * ft_power(nb, pow - 1));
}

char	*ft_itoa(int nbr)
{
	int		sign;
	int		length;
	char	*result;
	int		i;

	length = 0;
	if ((sign = nbr) < 0)
		nbr = -nbr;
	while (ft_power(10, length) <= nbr)
		length++;
	result = (char*)malloc(sizeof(int) * length);
	result[0] = (nbr % 10) + 48;
	i = 1;
	while ((nbr /= 10) > 0)
	{
		result[i] = (nbr % 10) + 48;
		i++;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
