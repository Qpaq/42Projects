/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:06:41 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 11:47:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*get_unique_letters(char *word)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (word[i])
	{
		while (word[j])
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (word[i] == word[j])
				word[j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (word);
}

void	print_unique_letters(char *word1, char *word2)
{
	int		i;
	int		j;
	int		print;

	i = 0;
	j = 0;
	while (word2[i])
	{
		print = 1;
		while (word1[j])
		{
			if (word2[i] == word1[j] && word2[i] != '.' && word1[j] != '.')
				print = 0;
			j++;
		}
		if (print && word2[i] != '.')
			write(1, &word2[i], 1);
		j = 0;
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 3)
	{
		av[1] = get_unique_letters(av[1]);
		av[2] = get_unique_letters(av[2]);
		while (av[1][i])
		{
			if (av[1][i] != '.')
				write(1, &av[1][i], 1);
			i++;
		}
		print_unique_letters(av[1], av[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
