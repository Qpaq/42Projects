/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 19:42:18 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 20:40:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int nb)
{
	int		i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i <= (nb / 2))
	{
		if (((double)nb / (double)i) - (nb / i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (is_prime(nb))
		return (nb);
	return (next_prime(nb + 1));
}

int		fprime(int nb, int prime)
{
	if (nb < 1)
	{
		printf("\n");
		return (0);
	}
	if (nb == 1)
		return (1);
	if (((double)nb / (double)prime) - (nb / prime) == 0)
	{
		if (nb / prime == 1)
			printf("%d\n", prime);
		else
			printf("%d*", prime);
		return (fprime(nb / prime, next_prime(prime)));
	}
	return (fprime(nb, next_prime(prime + 1)));
}

int		check_number(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	if (!check_number(argv[1]))
	{
		printf("\n");
		return (0);
	}
	if (atoi(argv[1]) == 1)
	{
		printf("1\n");
		return (0);
	}
	fprime(atoi(argv[1]), 2);
	return (0);
}
