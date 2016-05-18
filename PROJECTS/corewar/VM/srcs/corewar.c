/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:39:16 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 18:40:58 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			set_champion_number(t_vm *vm, int max)
{
	int		i;

	i = 0;
	while (i < vm->champ_nb)
	{
		if (vm->champions[i].number == -1)
			vm->champions[i].number = ++max;
		if (vm->champions[i].number <= 0)
			ft_error("Error: bad argument for -n");
		i++;
	}
}

void			check_champion_number(t_vm *vm)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i < vm->champ_nb)
	{
		j = 0;
		if (vm->champions[i].number > max)
			max = vm->champions[i].number;
		while (j < vm->champ_nb)
		{
			if (vm->champions[i].number == vm->champions[j].number && i != j
					&& vm->champions[j].number != -1)
				ft_error("Error: same number for champions");
			j++;
		}
		i++;
	}
	set_champion_number(vm, max);
}

static void		introduce_champs(t_vm *vm)
{
	int		i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < vm->champ_nb)
	{
		ft_printf("* Player %d: '%s' ('%s') ! \n", vm->champions[i].number,
												vm->champions[i].name,
												vm->champions[i].comment);
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_vm		vm;

	init_vm(&vm);
	check_errors(argc, argv);
	check_cor_files(argc, argv);
	get_vm(&vm, argv, argc);
	check_champion_number(&vm);
	load_champions(&vm);
	introduce_champs(&vm);
	start_running_vm(&vm);
	return (0);
}
