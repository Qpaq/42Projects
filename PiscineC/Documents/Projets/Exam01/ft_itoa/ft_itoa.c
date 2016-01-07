/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 19:30:48 by exam              #+#    #+#             */
/*   Updated: 2015/08/14 20:52:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		power(int nb, int puiss)
{
	if (puiss == 0)
		return (1);
	return (nb * power(nb, puiss - 1));
}

int		extract1(unsigned int nb)
{
	double	i;
	int		printnb;

	i = 1000000000;
	if (nb == 0)
		return (0);
	while (i > nb)
		i /= 10;
	printnb = nb / i;
	return (printnb);
}

int		extract2(unsigned int nb)
{
	double	i;
	int		printnb;

	i = 1000000000;
	if (nb == 0)
		return (0);
	while (i > nb)
		i /= 10;
	printnb = nb / i;
	return (printnb * i);
}

char	*ft_itoa(int nbr)
{
	int		size;
	char	*tab;
	int		temp;
	int		i;

	temp = nbr < 0 ? -nbr : nbr;
	size = 0;
	while (temp >= power(10, size))
		size++;
	size = nbr < 0 ? size + 1 : size;
	tab = (char*)malloc(size + 1);
	i = nbr < 0 ? 1 : 0;
	tab[0] = nbr < 0 ? '-' : '0';
	tab[1] = '\0';
	if (nbr == 0)
		return (tab);
	while (i < size)
	{
		tab[i] = extract1(temp) + 48;
		temp = temp - extract2(temp);
		i++;
	}
	tab[size] = '\0';
	return (tab);
}
