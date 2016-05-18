/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:38:22 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 18:38:50 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		is_number(char *str)
{
	int			i;

	i = 0;
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		is_file(char *str)
{
	int			ret;

	if ((ret = open(str, O_RDONLY)) == -1)
		return (0);
	else
	{
		close(ret);
		return (1);
	}
}

static void		check_errors_args(int argc, char **argv, int *nb_players)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-dump")
			&& (i >= argc - 1 || !is_number(argv[i + 1])))
			ft_error("Error: bad argument for -dump");
		if (!ft_strcmp(argv[i], "-n") && is_file(argv[i + 2]) && (i >= argc - 2
			|| !is_number(argv[i + 1])))
			ft_error("Error: bad argument for -n");
		if (!ft_strcmp(argv[i], "-dump"))
			i++;
		else if (!ft_strcmp(argv[i], "-n"))
		{
			*nb_players += 1;
			i += 2;
		}
		else if (!is_file(argv[i]))
			ft_error("Error: could not read file");
		else
			*nb_players += 1;
		i++;
	}
}

void			check_errors(int argc, char **argv)
{
	int			nb_players;

	nb_players = 0;
	if (argc <= 1)
		ft_error("Error: no argument");
	check_errors_args(argc, argv, &nb_players);
	if (nb_players > MAX_PLAYERS || nb_players == 0)
		ft_error("Error: wrong number of players");
}
