/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 13:24:45 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/24 22:37:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_power(int n, int pow);
char	*ft_strrev(char *str);

char	*ft_itoa(int nb)
{
	char	*str;
	int		i;
	int		sign;
	int		size;

	if ((sign = nb) < 0)
		nb = -nb;
	size = 0;
	while (nb >= ft_power(10, size))
		size++;
	str = (char*)malloc(size + 1);
	i = 1;
	str[0] = (nb % 10) + 48;
	while ((nb /= 10) > 0)
		str[i++] = (nb % 10) + 48;
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_strrev(str);
	return (str);
}
