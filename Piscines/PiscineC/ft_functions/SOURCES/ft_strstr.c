/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 16:40:25 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/12 10:43:45 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
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
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + i2] == to_find[i2])
		{
			if (i2 == size_tofind - 1)
				return (str + i);
			i2++;
		}
		i2 = 0;
		i++;
	}
	return ((void*)0);
}
