/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:51:44 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 18:28:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		pgcd(int nb1, int nb2)
{
	int		pgcd;
	int		max;
	int		i;

	pgcd = 1;
	max = nb1 <= nb2 ? nb1 : nb2;
	i = 1;
	while (i <= max)
	{
		if ((((double)nb1 / (double)i) - (nb1 / i) == 0)
				&& (((double)nb2 / (double)i) - (nb2 / i) == 0))
			pgcd = i;
		i++;
	}
	return (pgcd);
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
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	if (!check_number(argv[1]) || !check_number(argv[2]))
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
