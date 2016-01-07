/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 20:47:52 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/08 21:29:02 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int number, int power)
{
	int		result;
	int		n;

	result = 1;
	n = 0;
	while (n < power)
	{
		result *= number;
		n++;
	}
	return (result);
}

int		ft_atoi(char *str)
{
	int		n;
	int		number;
	int		length;
	int		temp;
	int		power;

	n = 0;
	number = 0;
	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	power = length - 1;
	while (n < length)
	{
		temp = str[n] - 48;
		temp *= ft_power(10, power);
		number += temp;
		n++;
		power--;
	}
	return (number);
}
