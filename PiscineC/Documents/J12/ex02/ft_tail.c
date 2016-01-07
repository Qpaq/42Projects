/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 15:46:34 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/21 13:06:41 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

int		ft_atoi(char *str)
{
	int		number;
	int		index;
	int		size;
	int		neg;

	size = 0;
	number = 0;
	neg = str[0] == '-' ? 1 : 0;
	while (str[size])
		size++;
	index = str[0] == '-' ? 1 : 0;
	while (str[index])
	{
		number += (str[index] - 48) * ft_power(10, size - index - 1);
		index++;
	}
	number = neg == 1 ? -number : number;
	return (number);
}

void	ft_tail(char *file, int output_size)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		file_size;
	int		to_write;

	if (-1 == (fd = open(file, O_RDONLY)))
		write(2, "Problem opening file\n", 21);
	else
	{
		file_size = read(fd, buf, BUF_SIZE);
		to_write = file_size - output_size;
		while (buf[to_write])
		{
			write(1, &buf[to_write], 1);
			to_write++;
		}
		close(fd);
	}
}
