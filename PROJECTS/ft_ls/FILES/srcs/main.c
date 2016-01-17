/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:00 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 11:15:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_ls_args		*ls_args;

	if (!(ls_args = (t_ls_args *)ft_memalloc(sizeof(t_ls_args))))
		return (0);
	ls_args->authorized_options = ft_strdup("RalrtGsS");
	check_arguments(ac, av, ls_args);
	ls_args->dirs = sort_from_options(ls_args->dirs, ls_args->options);
	browse_directories(ls_args);
	free_main_struct(ls_args);
	return (0);
}
