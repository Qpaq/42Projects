/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 14:38:14 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/08 20:46:23 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	temp_char;
	int		length;
	int		n;

	n = 0;
	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	while (n < length / 2)
	{
		temp_char = str[n];
		str[n] = str[length - n - 1];
		str[length - n - 1] = temp_char;
		n++;
	}
	return (str);
}
