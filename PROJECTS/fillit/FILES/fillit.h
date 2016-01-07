/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:40:25 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 10:44:01 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_fmap
{
	int			*tab[27];
	int			size;
	int			square_size;
}					t_fmap;

int					ft_sqrt_max(int nbr);
int					*shift_left(int *pos);
int					check_file(int fd, t_fmap *c_map);
int					check_tetriminos(char *tetri);
void				increment_square_size(t_fmap *map);
int					backtrack_tetri(t_fmap *tetri, char *fmap, int line);
int					fillit(int fd);

#endif
