/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 18:29:31 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/12 09:59:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (s1[0] == '\0' && s1[0] != s2[0])
		return (-1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (0);
			i++;
			continue;
		}
		else
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
