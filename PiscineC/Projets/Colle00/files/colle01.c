/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:21:23 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/09 20:46:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int line, int column, int length, int height)
{
	if ((column == 1 && line == 1)
		|| (line == height && column == length && column != 1 && line != 1))
	{
		ft_putchar('/');
	}
	else if ((line == 1 && column == length)
			|| (column == 1 && line == height))
	{
		ft_putchar('\\');
	}
	else if (line != 1 && column != length && column != 1 && line != height)
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('*');
	}
	if (column == length)
	{
		ft_putchar('\n');
	}
}

void	colle(int x, int y)
{
	int		line;
	int		column;

	line = 1;
	column = 1;
	while (line <= y)
	{
		while (column <= x)
		{
			print_line(line, column, x, y);
			column++;
		}
		column = 1;
		line++;
	}
}
