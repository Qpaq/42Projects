/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 17:19:33 by exam              #+#    #+#             */
/*   Updated: 2015/08/21 17:28:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search_and_replace(char *str, char old, char new)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
