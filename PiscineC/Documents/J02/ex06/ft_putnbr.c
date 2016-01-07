/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 14:50:55 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/07 22:08:42 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	double	i;
	char	a_imprimer;

	i = 10000000000;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (i > nb)
	{
		i /= 10;
	}
	while (i >= 1)
	{
		a_imprimer = nb / i;
		nb = nb - (a_imprimer * i);
		a_imprimer = a_imprimer + 48;
		ft_putchar(a_imprimer);
		i /= 10;
	}
}
