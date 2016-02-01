/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 17:07:30 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_base_bis(uintmax_t nbr, char *base, size_t base_len)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base_bis(nbr / base_len, base, base_len);
		ft_putnbr_base_bis(nbr % base_len, base, base_len);
	}
	else
		ft_putchar(base[nbr]);
}

void			ft_putnbr_base(uintmax_t nbr, char *base)
{
	ft_putnbr_base_bis(nbr, base, ft_strlen(base));
}
