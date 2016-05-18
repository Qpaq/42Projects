/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:04:14 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:37:58 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	if (base == 10)
		ft_putnbr(n);
	else if (n < 0)
		ft_putchar('0');
	else
	{
		if (n >= base)
			ft_putnbr_base(n / base, base);
		if (n % base < 10)
			ft_putchar((n % base) + 48);
		else
			ft_putchar((n % base) - 10 + 65);
	}
}
