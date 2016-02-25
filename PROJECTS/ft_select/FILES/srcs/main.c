/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:12:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/09 11:24:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putchar_select(int c)
{
	int		fd;

	fd = open(ttyname(0), O_WRONLY);
	write(fd, &c, 1);
	close(fd);
	return (1);
}

int		check_capability(char *cap)
{
	if (tgetflag(cap) == 0 && tgetnum(cap) == -1 && tgetstr(cap, NULL) == 0)
		return (0);
	return (1);
}

void	parse_arguments(int argc, char **argv, t_select *params)
{
	int			i;
	t_args_list	*new;
	t_args_list	*list;

	list = params->list;
	list->value = ft_strdup(argv[0]);
	i = 0;
	while(i < argc)
	{
		new = (t_args_list *)ft_memalloc(sizeof(t_args_list));
		new->value = ft_strdup(argv[i]);
		list->next = new;
		list = list->next;
		i++;
	}
}


// A SUPPRIMER
void	test_capability(void)
{
	char	*res;
	res = tgetstr("cl", NULL);
	tputs(res, 1, putchar_select);
}

t_select	*init_struct(void)
{
	t_select	*params;
	t_args_list	*head_list;

	if ((params = (t_select *)ft_memalloc(sizeof(t_select))) == NULL)
		return (NULL);
	if ((head_list = (t_args_list *)ft_memalloc(sizeof(t_args_list))) == NULL)
		return (NULL);
	params->list = head_list;
	return (params);
}

int		main(int argc, char **argv)
{
	char			*term_name;
	t_select		*params;

	if (argc <= 1)
		return (-1);
	if ((term_name = getenv("TERM")) == NULL)
	{
		ft_putendl("Cannot find environment variable TERM");
		return (-1);
	}
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (init_raw_mode() == -1)
		return (-1);
	params = init_struct();
	parse_arguments(--argc, ++argv, params);
	ft_signals();
//	test_capability();
	ft_putchar('o');
	get_key(params);
	restore_terminal();
	return (0);
}
