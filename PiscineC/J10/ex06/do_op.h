/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 18:51:51 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/19 19:50:59 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

typedef	struct	s_operators
{
}				t_operators;

int		add(int nb1, int nb2);
int		substract(int nb1, int nb2);
int		multiply(int nb1, int nb2);
int		divide(int nb1, int nb2);
int		modulo(int nb1, int nb2);

int		ft_atoi(char *str);
int		do_op(int nb1, char *oper, int nb2);

void	ft_putnbr(int nb);

#endif
