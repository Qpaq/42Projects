/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 10:56:16 by exam              #+#    #+#             */
/*   Updated: 2015/12/29 11:38:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_strrev(char *str)
{
	int		i;
	char	temp;
	int		length;

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

static long		ft_power(long n, int power)
{
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

char			*ft_itoa_base(int value, int base)
{
	char	*result;
	int		length;
	long	n;
	int		sign;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (long)value;
	sign = 1;
	if (n < 0)
	{
		if (base == 10)
		{
			sign = -1;
			n = -n;
		}
		else
			return (NULL);
	}
	length = 1;
	while (ft_power(base, length) <= n)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base <= 10)
			result[i] = (n % base) + 48;
		else
		{
			if (n % base < 10)
				result[i] = (n % base) + 48;
			else
				result[i] = (n % base) - 10 + 65;
		}
		n /= base;
		i++;
	}
	if (sign == -1)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
