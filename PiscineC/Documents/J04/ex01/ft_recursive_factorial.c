/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 11:26:47 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/10 12:56:45 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb >= 0)
	{
		if (nb == 0 || nb == 1)
			return (1);
		return (nb * ft_recursive_factorial(nb - 1));
	}
	return (0);
}
