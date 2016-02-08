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

int		reset_struct(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}

int		raw_mode(struct termios *term)
{
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	return (0);
}

int		main(void)
{
	char			*term_name;
	struct termios	term;

	if ((term_name = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	raw_mode(&term);
	get_key();
	reset_struct(&term);
	return (0);
}
