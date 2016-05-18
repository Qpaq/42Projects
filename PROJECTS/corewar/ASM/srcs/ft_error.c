/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 13:36:46 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/11 17:40:38 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_error(int error, char *txt, int nl)
{
	if (error == 0)
		ft_printf("{red}Problem Malloc.{eoc}\n");
	else if (error == 1)
		ft_printf("{red}l.%d: Syntax Error on the %s.{eoc}\n", nl, txt);
	else if (error == 2)
		ft_printf("{red}l.%d: Syntax error.{eoc}\n", nl);
	else if (error == 3)
		ft_printf("{red}l.%d: Problem on line.{eoc}\n", nl);
	else if (error == 4)
		ft_printf("{red}l.%d: Bad argument.{eoc}\n", nl);
	else if (error == 5)
		ft_printf("{red}l.%d: Bad argument syntax.{eoc}\n", nl);
	else if (error == 6)
		ft_printf("{red}Error with label \"%s\".{eoc}\n", txt);
	else if (error == 7)
		ft_printf("{red}l.%d: Error with registre number \"%s\".{eoc}\n",
				nl, txt);
	else if (error == 8)
		ft_printf("{red}l.%d: End of file with no instructions.{eoc}\n", nl);
	else if (error == 9)
		ft_printf("{red}l.%d: Argument [%s] is not valid.{eoc}\n", nl, txt);
	else if (error == 10)
		ft_printf("{red}Le \"%s\" est trop grand.\n", txt);
	exit(1);
}
