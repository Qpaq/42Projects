/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 08:27:40 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 09:05:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (1);
	if (base % 2 == 0)
		return (ft_collatz_conjecture(base /= 2));
	else
		return (ft_collatz_conjecture(base * 3 + 1));
}
