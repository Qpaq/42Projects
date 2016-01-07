/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 12:10:22 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 13:40:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_power(int n, int pow)
{
	if (n < 0 || pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}

void	ft_strrev(char *str)
{
	int		i;
	int		length;
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
}

char	*ft_itoa_base(int value, int base)
{
	int		sign;
	int		size;
	char	*result;
	int		i;

	size = 0;
	while (value > ft_power(10, size))
		size++;
	if ((sign = value) < 0)
	{
		value = -value;
		size++;
	}
	result = (char*)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (value > 0)
	{
		result[i++] = (value % base) + 48;
		value /= base;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
