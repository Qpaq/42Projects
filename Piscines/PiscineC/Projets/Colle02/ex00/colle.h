/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 14:26:14 by alhote            #+#    #+#             */
/*   Updated: 2015/08/23 20:36:59 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE_H
# define COLLE_H

# define MSG_ERREUR "aucune\n"

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_rectangle_spec
{
	int				colle;
	char			hg;
	char			hd;
	char			bg;
	char			bd;
	char			ch;
	char			cc;
	int				size_x;
	int				size_y;
}					t_rectangle_spec;

int					try_parse(t_rectangle_spec *colle, char *rectangle);
void				colle(char *rectangle);

void				ft_putstr(char *str);
void				ft_putnbr(int nb);
void				ft_putchar(char c);

#endif
