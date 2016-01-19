/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:02:42 by exam              #+#    #+#             */
/*   Updated: 2016/01/19 10:44:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_power(int n, int pow)
{
	if (pow == 0)
		return (1);
	return (n * ft_power(n, pow - 1));
}

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	tmp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < (length / 2))
	{
		tmp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		length;
	char	*str;
	long	sign;
	long	nb;

	if (value < 0 && base == 10)
	{
		sign = -1;
		nb =(long)-value;
	}
	else if (value < 0 && base != 10)
		return (NULL);
	else
	{
		sign = 1;
		nb = (long)value;
	}
	length = 1;
	while (ft_power(base, length) <= nb)
		length++;
	if (!(str = (char *)malloc(sizeof(char) * (length + 2))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		if (base <= 10 || (base > 10 && (nb % base) < 10 ))
			str[i] = (nb % base) + 48;
		else
			str[i] = (nb % base) - 10 + 65;
		nb /= base;
		i++;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
