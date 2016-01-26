/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 10:20:59 by exam              #+#    #+#             */
/*   Updated: 2016/01/26 10:49:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_power(long n, long pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}

char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	long	nb;
	long	length;
	char	*result;
	int		sign;
	int		i;

	nb = (long)value;
	if (base < 2 || base > 16)
		return (NULL);
	if (base != 10 && nb < 0)
		return (NULL);
	if (base == 10 && nb < 0)
	{
		sign = -1;
		nb = -nb;
	}
	else
		sign = 1;
	length = 1;
	while (ft_power(base, length) <= nb)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 2));
	i = 0;
	while (i < length)
	{
		if (base <= 10 || (base > 10 && (nb % base) < 10))
			result[i] = (nb % base) + 48;
		else
			result[i] = (nb % base) - 10 + 65;
		nb /= base;
		i++;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
