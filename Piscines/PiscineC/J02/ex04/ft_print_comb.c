/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 15:49:52 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/07 22:12:02 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_numbers(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a != '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char first;
	char second;
	char third;

	first = '0';
	second = '1';
	third = '2';
	while (first <= '9')
	{
		while (second <= '9')
		{
			while (third <= '9')
			{
				if (first != second && second != third && first != third)
				{
					print_numbers(first, second, third);
				}
				third++;
			}
			second++;
			third = second;
		}
		first++;
		second = first;
	}
}
