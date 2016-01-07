/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 16:19:33 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/17 19:09:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		count_words(char *str)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		size;
	int		current_word;

	size = count_words(str);
	tab = (char**)malloc(size * sizeof(char*));
	current_word = 0;
	while(*str)
	{
		if (*str == '\t' || *str == '\n' || *str == ' ')
		{
			current_word++;
			str++;
		}
		ft_strcpy(tab[current_word], str);
		str++;
	}
	return (tab);
}

int main()
{
	char *test = "Je fais un test";
	ft_split_whitespaces(test);
	int i=0;
	while (i < 4)
	{
		printf("%s", test);
		i++;
	}
	return (0);
}
