/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 11:45:40 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 12:04:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
	{
		ft_putchar(str[n]);
		n++;
	}
}

void	ft_putnbr(int nb)
{
	double	i;
	char	a_imprimer;

	i = 10000000000;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (i > nb)
	{
		i /= 10;
	}
	while (i >= 1)
	{
		a_imprimer = nb / i;
		nb = nb - (a_imprimer * i);
		a_imprimer = a_imprimer + 48;
		ft_putchar(a_imprimer);
		i /= 10;
	}
}

int		ft_power(int number, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (number * ft_power(number, power - 1));
}

int		ft_atoi(char *str)
{
	int		result;
	int		i;
	int		temp;
	int		size;

	i = 0;
	result = 0;
	size = 0;
	while (str[size] != '\0')
		size++;
	while (str[i] != '\0')
	{
		temp = str[i] - 48;
		result += temp * ft_power(10, (size - 1) - i);
		i++;
	}
	return (result);
}
