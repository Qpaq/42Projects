/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 11:39:56 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 12:42:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_putstr(char*);

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

char	*ft_strcat(char *dest, char *src)
{
	int		size_dest;
	int		i;

	i = 0;
	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[i] != '\0')
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_join(char **tab, char *sep)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(*tab));
	i = 1;
	str = ft_strcpy(str, tab[0]);
	while (tab[i])
	{
		str = ft_strcat(str, tab[i]);
		str = ft_strcat(str, sep);
		i++;
	}
	str = ft_strcat(str, "\0");
	return (str);
}

int main()
{
	char *test[4] = {"david", "simon", "quentin", "dieuson"};
	ft_putstr(ft_join(test, "salut"));
}
