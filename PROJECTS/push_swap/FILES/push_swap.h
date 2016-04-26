/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:36:44 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 17:36:46 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_pushswap
{
	int		*pile_a;
	int		length_a;
	int		smallest_a;
	int		pos_smallest_a;
	int		*pile_b;
	int		length_b;
	char	*sequence;
	int		nb_of_moves;
	int		verbose;
	int		fast;
}				t_pushswap;

void			push_a(t_pushswap *data);
void			push_b(t_pushswap *data);
void			swap_a(t_pushswap *data);
void			swap_b(t_pushswap *data);
void			swap_ab(t_pushswap *data);
void			rotate_a(t_pushswap *data);
void			rotate_b(t_pushswap *data);
void			rotate_ab(t_pushswap *data);
void			reverse_rotate_a(t_pushswap *data);
void			reverse_rotate_b(t_pushswap *data);
void			reverse_rotate_ab(t_pushswap *data);

int				check_pile(int *pile, int length);
void			sort_pile(t_pushswap *data);

void			print_pile(int *pile, int length);
void			print_state(t_pushswap *data);

#endif
