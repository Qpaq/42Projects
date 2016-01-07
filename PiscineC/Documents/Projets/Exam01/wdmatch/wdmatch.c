/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 17:38:12 by exam              #+#    #+#             */
/*   Updated: 2015/08/14 18:11:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[2][j] != '\0')
	{
		if (argv[2][j] == argv[1][i])
			i++;
		j++;
	}
	if (argv[1][i] == '\0')
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
