/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 12:07:10 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 14:32:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		eval_expr(char *expression)
{
}

char	**create_final_list(char **tab)
{
	int		i;

	while (tab[i])
	{

	}
}

int		calculate(int nb1, char *oper, int nb2)
{
	if (oper[0] == '+')
		return (add(nb1, nb2));
	else if (oper[0] == '-')
		return (substract(nb1, nb2));
	else if (oper[0] == '*')
		return (multiply(nb1, nb2));
	else if (oper[0] == '/')
		return (divide(nb1, nb2));
	else if (oper[0] == '%')
		return (modulo(nb1, nb2));
	else
		return (0);
}
