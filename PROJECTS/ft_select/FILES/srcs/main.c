/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:12:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/08 14:07:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_key(void)
{
	char	*key;

	while (42)
	{
		key = ft_strnew(3);
		read(0, key, 3);
		if (key[0] == 27 && key[1] == 0)
			break ;
		ft_printf("0: %d\n1: %d\n2: %d\n3: %d\n\n", key[0], key[1], key[2], key[3]);
		free(key);
	}
}

int		main(void)
{
	char			*term_name;
	struct termios	term;

	if ((term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (raw_mode(&term) == -1)
		return (-1);
	ft_signals();
	get_key();
	reset_settings();
	return (0);
}
