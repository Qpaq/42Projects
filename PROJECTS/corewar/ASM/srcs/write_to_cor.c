/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:02:54 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 17:02:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_magic(int fd, unsigned int magic)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = (magic >> 24) & 0xff;
	b = (magic >> 16) & 0xff;
	c = (magic >> 8) & 0xff;
	d = magic & 0xff;
	write(fd, &a, 1);
	write(fd, &b, 1);
	write(fd, &c, 1);
	write(fd, &d, 1);
}

void	write_args(int fd, t_instruct *current, char **args, t_instruct *head)
{
	int		i;
	t_op	*tab;

	tab = return_op_tab(current->instruction);
	i = 0;
	while (args[i])
	{
		if (args[i][0] == DIRECT_CHAR)
		{
			if (args[i][1] == LABEL_CHAR)
				write_label_pos(fd, &args[i][2], current, head);
			else
				write_number(fd, &args[i][1], tab->label_size);
		}
		else if (args[i][0] == 'r')
			write_number(fd, &args[i][1], 1);
		else
			write_number(fd, &args[i][0], 2);
		i++;
	}
}

void	write_instruction(int fd, t_instruct *instruct, t_instruct *head)
{
	t_op	*tab;

	tab = return_op_tab(instruct->instruction);
	write(fd, &(tab->op_code), 1);
	if (instruct->ocp != -1)
		write(fd, &(instruct->ocp), 1);
	if (instruct->arguments)
		write_args(fd, instruct, instruct->arguments, head);
}

void	write_header(int fd, t_header *header, t_instruct *instruct)
{
	int		prog_size;

	prog_size = 0;
	write_magic(fd, header->magic);
	write_string_to_file(fd, header->prog_name, PROG_NAME_LENGTH + 4);
	while (instruct)
	{
		prog_size += instruct->size;
		instruct = instruct->next;
	}
	write_number(fd, ft_itoa(prog_size), 4);
	write_string_to_file(fd, header->comment, COMMENT_LENGTH + 4);
}

void	write_to_cor(char *name, t_header *header, t_instruct *instruct)
{
	int			fd;
	t_instruct	*head;

	head = instruct;
	name = ft_strjoin(name, ".cor");
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
		error_exit("Could not create COR file");
	write_header(fd, header, instruct);
	while (instruct)
	{
		if (instruct->instruction)
			write_instruction(fd, instruct, head);
		instruct = instruct->next;
	}
	close(fd);
}
