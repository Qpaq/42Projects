/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:41:01 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 13:21:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*get_first_word(char *str)
{
	char	*word;
	int		size;
	int		i;
	int		j;

	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	size = 0;
	j = i;
	while (str[j] != '\0' && str[j] != 32 && str[j] != 9)
	{
		j++;
		size++;
	}
	word = (char*)malloc(size);
	j = 0;
	while (j < size)
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

int		start_new_string(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
		i++;
	while (str[i] != '\0' && str[i] != 32 && str[i] != 9)
		i++;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
		i++;
	if (str[i] == 0)
		return (0);
	else
		return (i);
}

void	trim_spaces(char *str)
{
	int		i;
	int		space;

	i = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
	{
		str[i] = 4;
		i++;
	}
	while (str[i])
	{
		if (str[i] != '\0' && str[i] != 32 && str[i] != 9)
		{
			space = 0;
			i++;
		}
		else if (str[i] != '\0' && (str[i] == 32 || str[i] == 9))
		{
			if (space == 1)
				str[i] = 4;
			else
			{
				space = 1;
				i++;
			}
		}
	}
}

int		main()
{
}
