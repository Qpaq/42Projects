/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 09:38:07 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/07 22:53:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	affichage_nombres(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	char first1;
	char first2;
	char second1;
	char second2;

	first1 = '0';
	first2 = '0';
	second1 = '0';
	second2 = '1';
	while (first1 <= '9')
	{
		while (first2 <= '9')
		{
			while (second1 <= '9')
			{
				while (second2 <= '9')
				{
					affichage_nombres(first1, first2, second1, second2);
					second2++;
				}
				second2 = first1;
				second1++;
			}
			second1 = first2;
			first2++;
		}
		first2 = '0';
		first1++;
	}
}
