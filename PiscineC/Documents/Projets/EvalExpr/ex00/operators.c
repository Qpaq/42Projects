/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 12:07:36 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 12:08:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		add(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int		substract(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int		multiply(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int		divide(int nb1, int nb2)
{
	if (nb2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	return (nb1 / nb2);
}

int		modulo(int nb1, int nb2)
{
	if (nb2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 24);
		return (0);
	}
	return (nb1 % nb2);
}
