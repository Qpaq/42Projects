/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 10:46:49 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 11:00:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	print_hex(unsigned int nb)
{
	if (nb >= 16)
		print_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) - 10 + 'a');
	else
		ft_putchar((nb % 16) + 48);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
