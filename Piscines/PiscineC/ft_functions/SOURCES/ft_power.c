/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 13:15:01 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/17 13:12:13 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int number, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	return (number * ft_power(number, power - 1));
}