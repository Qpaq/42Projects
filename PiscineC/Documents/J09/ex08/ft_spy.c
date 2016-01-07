/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 09:06:36 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 09:34:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

int		ft_strstr(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		size_tofind;

	i = 0;
	i2 = 0;
	size_tofind = 0;
	while (to_find[size_tofind] != '\0')
		size_tofind++;
	if (size_tofind == 0)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i + i2] == to_find[i2])
		{
			if (i2 == size_tofind - 1)
				return (1);
			i2++;
		}
		i2 = 0;
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		argv[i] = ft_strlowcase(argv[i]);
		if (ft_strstr(argv[i], "president") == 1
			|| ft_strstr(argv[i], "attack") == 1
			|| ft_strstr(argv[i], "powers") == 1)
		{
			write(1, "Alert!!!\n", 9);
			break ;
		}
		i++;
	}
	return (0);
}
