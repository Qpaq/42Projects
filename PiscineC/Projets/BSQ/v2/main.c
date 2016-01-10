/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:25:04 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 16:19:23 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		print_grid(char **grid, t_grid_specs *specs)
{
	int		i;

	i = 0;
	while (i < (specs->lines))
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

int			ft_strcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (*str1 == *str2 && *str1 == '\0')
		return (1);
	return (0);
}

char		*init_grid_str(int ac, char **av, int i)
{
	char	*grid;

	if (ac == 1)
		grid = get_from_stdin();
	else
		grid = get_from_file(av[i]);
	return (grid);
}

int			main(int argc, char **argv)
{
	char			*grid;
	int				i;
	t_grid_specs	*specs;
	char			**tab;
	int				start;

	i = 1;
	while (i < argc || (argc == 1 && i == 1))
	{
		if (NULL == (specs = (t_grid_specs*)malloc(sizeof(t_grid_specs))))
			return (0);
		grid = init_grid_str(argc, argv, i);
		if (!(start = check_grid(grid, specs)) || ft_strcmp(grid, "map error"))
		{
			write(2, "map error\n", 10);
			return (0);
		}
		else
		{
			tab = grid_str_to_tab(grid, specs, start);
			free(grid);
			final_grid(tab, specs);
			print_grid(tab, specs);
		}
		free_tab(tab, specs);
		i++;
	}
	return (0);
}
