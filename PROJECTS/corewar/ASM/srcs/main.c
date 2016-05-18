/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 17:03:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
		error_exit("Wrong number of arguments");
	parse_file(argv[argc - 1]);
	get_cor_file(argv[argc - 1]);
	return (0);
}
