/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cor_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 19:41:00 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_string_to_file(int fd, char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	error_exit(char *message)
{
	ft_putendl(message);
	exit(0);
}

char	*check_file_name(char *arg)
{
	char	*name;
	char	*extension;

	name = ft_strsub(arg, 0, ft_strlen(arg) - 2);
	extension = ft_strsub(arg, ft_strlen(arg) - 2, ft_strlen(arg) - 1);
	if (ft_strcmp(extension, ".s") == 0)
		return (name);
	else
		error_exit("Wrong file name");
	return (NULL);
}

void	print_instructions_list(t_instruct *instruct, t_header *header)
{
	ft_printf("%s\n%s\n", header->prog_name, header->comment);
	while (instruct)
	{
		ft_printf("address: %p\n", instruct);
		ft_printf("name: %s, size: %d, position: %d\n",
				instruct->instruction, instruct->size, instruct->position);
		ft_printf("label: %s\n", instruct->label);
		ft_putendl("Args:");
		if (instruct->arguments)
			ft_putstr_array(instruct->arguments, '/');
		else
			ft_putstr("NO ARGS");
		ft_printf("\nOCP: %d\n", instruct->ocp);
		instruct = instruct->next;
		ft_putendl("\n");
	}
}

void	get_cor_file(char *arg)
{
	int				fd;
	t_header		*header;
	t_instruct		*instruct;
	char			*file_name;

	file_name = check_file_name(arg);
	if ((fd = open(arg, O_RDONLY)) == -1)
		error_exit("Couldn't open file");
	if ((header = (t_header *)ft_memalloc(sizeof(t_header))) == NULL)
		error_exit("Error malloc()");
	get_header(fd, header);
	if ((instruct = (t_instruct *)ft_memalloc(sizeof(t_instruct))) == NULL)
		error_exit("Error malloc()");
	lseek(fd, 0, SEEK_SET);
	instruct->position = -1;
	get_instructions(fd, &instruct);
	write_to_cor(file_name, header, instruct);
}
