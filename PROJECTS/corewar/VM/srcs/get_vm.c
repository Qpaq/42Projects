/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 15:39:39 by amanukya          #+#    #+#             */
/*   Updated: 2016/05/16 15:39:40 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		set_champ(t_vm *vm, int number, char *buf, int len)
{
	char			*name;
	char			*comment;
	unsigned char	*data;
	int				cursor;
	int				data_len;

	cursor = 4;
	name = ft_strsub(buf, cursor, PROG_NAME_LENGTH);
	cursor += PROG_NAME_LENGTH + 8;
	comment = ft_strsub(buf, cursor, COMMENT_LENGTH);
	cursor += COMMENT_LENGTH + 4;
	data_len = len - cursor;
	data = (unsigned char *)ft_strnew(data_len);
	ft_memcpy(data, buf + cursor, data_len);
	vm->champions[number].name = name;
	vm->champions[number].comment = comment;
	vm->champions[number].data = data;
	vm->champions[number].data_len = data_len;
}

static void		read_champion(t_vm *vm, int num, char *champ)
{
	int		len;
	int		fd;
	char	buf[FILE_MAX_SIZE];

	if ((fd = open(champ, O_RDONLY)) == -1)
		ft_error("Error: Could not open file:");
	len = read(fd, buf, FILE_MAX_SIZE);
	set_champ(vm, num, buf, len);
	close(fd);
}

void			get_vm(t_vm *vm, char **argv, int argc)
{
	int			i;

	i = 1;
	while (i < argc && vm->champ_nb < MAX_PLAYERS)
	{
		if (ft_strcmp(argv[i], "-dump") == 0)
		{
			vm->dump_cycle = ft_atoi(argv[i + 1]);
			i += 2;
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
		{
			read_champion(vm, vm->champ_nb, argv[i + 2]);
			vm->champions[vm->champ_nb].number = ft_atoi(argv[i + 1]);
			i += 3;
			vm->champ_nb++;
		}
		else
		{
			read_champion(vm, vm->champ_nb, argv[i]);
			vm->champ_nb++;
			i++;
		}
	}
}
