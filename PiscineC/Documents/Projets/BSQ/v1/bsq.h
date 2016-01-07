/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:25:59 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 17:09:22 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_grid_specs
{
	int		lines;
	int		columns;
	char	empty;
	char	obstacle;
	char	filled;
}				t_grid_specs;

typedef struct	s_max
{
	int		line;
	int		col;
	int		value;
}				t_max;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_atoi(char *str);
int				ft_min(int *tab, int length);

char			*get_from_file(char *file);
char			*get_from_stdin(void);
char			**grid_str_to_tab(char *str, t_grid_specs *grid_specs, int i);
char			*ft_strcat(char *dest, char *src, int size);

int				check_grid(char *grid, t_grid_specs *specs);

void			free_tab(char **tab, t_grid_specs *specs);
void			free_tab_num(int **tab, t_grid_specs *specs);

char			**final_grid(char **grid, t_grid_specs *specs, int **grid_num);
int				**init_grid_num(char **grid, t_grid_specs *specs);

void			print_grid(char **grid, t_grid_specs *specs);

#endif
