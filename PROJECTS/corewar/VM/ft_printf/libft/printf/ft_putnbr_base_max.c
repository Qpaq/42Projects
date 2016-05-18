/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:43:38 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:56:09 by abungert         ###   ########.fr       */
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

void			ft_putnbr_base_max(uintmax_t nbr, char *base)
{
	ft_putnbr_base_bis(nbr, base, ft_strlen(base));
}
