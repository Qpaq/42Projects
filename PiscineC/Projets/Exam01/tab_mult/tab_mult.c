/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 18:16:14 by exam              #+#    #+#             */
/*   Updated: 2015/08/14 19:27:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	double	i;
	int		resultat;
	char	printnb;

	i = 1000000000;
	resultat = 0;
	if (nb < 0)
	{
		nb = -nb;
		ft_putstr("-");
	}
	if (nb == 0)
		ft_putstr("0");
	while (i > nb)
		i /= 10;
	while (i >= 1)
	{
		printnb = nb / i;
		nb = nb - printnb * i;
		printnb += 48;
		ft_putstr(&printnb);
		i /= 10;
	}
}

int		power(int nb, int puiss)
{
	if (puiss == 0)
		return (1);
	return (nb * power(nb, puiss - 1));
}

int		ft_atoi(char *nb)
{
	int		result;
	int		i;
	int		temp;
	int		size;

	i = 0;
	result = 0;
	size = 0;
	while (nb[size] != '\0')
		size++;
	while (nb[i] != '\0')
	{
		temp = nb[i] - 48;
		result += temp * power(10, (size - 1) - i);
		i++;
	}
	return (result);
}

int		main(int argc, char **argv)
{
	int		i;
	int		nb;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		i = 1;
		while (i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(nb);
			ft_putstr(" = ");
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
