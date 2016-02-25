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

void	parse_arguments(int argc, char **argv, t_select *main_list)
{
	int			i;
	t_select	*new;
	
	main_list->value = ft_strdup(argv[0]);
	i = 1;
	while(i < argc)
	{
		new = (t_select *)ft_memalloc(sizeof(t_select));
		new->value = ft_strdup(argv[i]);
		main_list->next = new;
		main_list = main_list->next;
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


int		main(int argc, char **argv)
{
	char			*term_name;
	t_select		*main_list;

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
	main_list = (t_select *)ft_memalloc(sizeof(t_select));
	parse_arguments(--argc, ++argv, main_list);
	ft_signals();
//	test_capability();
	ft_putchar('o');
	get_key(main_list);
	restore_terminal();
	return (0);
}
