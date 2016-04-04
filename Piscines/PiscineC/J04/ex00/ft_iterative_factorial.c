/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 11:27:33 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/10 12:59:42 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		result;

	if (nb > 0)
	{
		result = nb;
		while (nb > 1)
		{
			nb--;
			result *= nb;
		}
		return (result);
	}
	else if (nb == 0)
		return (1);
	return (0);
}
