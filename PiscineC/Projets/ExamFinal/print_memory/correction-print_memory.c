/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 13:55:12 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 14:45:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	print_hex(int nb)
{
	if (nb >= 16)
		print_hex(nb / 16);
	if ((nb % 16) >= 10)
		ft_putchar((nb % 16) - 10 + 'a');
	else
		ft_putchar((nb % 16) + 48);
}

void	print_memory(const void *addr/*, size_t size*/)
{
	print_hex((int)addr);
}

int main()
{
	char	*test = "david";
	printf("%p\n", &test);
	print_memory(&test);
}
