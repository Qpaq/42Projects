/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 18:51:18 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/19 19:56:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putnbr(int nb)
{
	double	i;
	char	a_imprimer;

	i = 10000000000;
	if (nb < 0)
	{
		write(1, "-", 1);
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
		write(1, &a_imprimer, 1);
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
	while (str[size] != '\0' && str[size] >= '0' && str[size] <= '9')
		size++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		temp = str[i] - 48;
		result += temp * ft_power(10, (size - 1) - i);
		i++;
	}
	return (result);
}

int		do_op(int nb1, char *oper, int nb2)
{
	if (oper[0] == '+')
		return (add(nb1, nb2));
	else if (oper[0] == '-')
		return (substract(nb1, nb2));
	else if (oper[0] == '*')
		return (multiply(nb1, nb2));
	else if (oper[0] == '/')
		return (divide(nb1, nb2));
	else if (oper[0] == '%')
		return (modulo(nb1, nb2));
	else
		return (0);
}
