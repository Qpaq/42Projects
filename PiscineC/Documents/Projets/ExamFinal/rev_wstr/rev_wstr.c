/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/29 11:07:54 by exam              #+#    #+#             */
/*   Updated: 2015/08/29 12:00:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		wordlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		count_words(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 1;
	if (wordlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**rev_wstr(char *str)
{
	char	**str_rev;
	int		words;
	int		i;
	int		j;
	int		current;

	i = 0;
	j = 0;
	words = count_words(str);
	current = wordlen(str);
	str_rev = (char**)malloc(sizeof(char*) * words);
	str_rev[i] = (char*)malloc(sizeof(char) * (current + 1));
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			str_rev[i++][j] = '\0';
			j = 0;
			current = wordlen(++str);
			str_rev[i] = (char*)malloc(sizeof(char) * (current + 1));
		}
		str_rev[i][j] = *str++;
		j++;
	}
	return (str_rev);
}

int		main(int argc, char **argv)
{
	char	**rev;
	int		i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev = rev_wstr(argv[1]);
	i = count_words(argv[1]);
	while (i > 0)
	{
		ft_putstr(rev[i - 1]);
		if (i != 1)
			ft_putstr(" ");
		i--;
	}
	write(1, "\n", 1);
	return (0);
}
