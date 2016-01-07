/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:04:57 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 17:18:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		free_tab(char **tab, t_grid_specs *specs)
{
	int		i;

	i = 0;
	while (i < specs->lines)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(specs);
}

void		free_tab_num(int **tab, t_grid_specs *specs)
{
	int		i;

	i = 0;
	while (i < specs->lines)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
