/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:57:25 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 10:33:26 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int	n;
	int	i;
	int	begin;

	begin = 0;
	while ((str[begin] >= 9 && str[begin] <= 13) || str[begin] == 32)
		begin = begin + 1;
	i = begin;
	if (str[i] == '-' || str[i] == '+')
		i = i + 1;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i = i + 1;
	}
	return (str[begin] == '-' ? -n : n);
}

int		ft_min(int *tab, int length)
{
	int		min;
	int		i;

	i = 1;
	min = tab[0];
	while (i < length)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	ft_putstr(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	write(1, str, ptr - str);
}
