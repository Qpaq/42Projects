/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 12:05:08 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 13:29:42 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <stdlib.h>
# include <unistd.h>

int		add(int nb1, int nb2);
int		substract(int nb1, int nb2);
int		multiply(int nb1, int nb2);
int		divide(int nb1, int nb2);
int		modulo(int nb1, int nb2);

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_power(int number, int power);

char	**ft_split_whitespaces(char *str);

#endif
