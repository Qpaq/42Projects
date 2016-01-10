/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 08:01:40 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 08:15:48 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_bouton(int i, int j, int k)
{
	int		tab[3];
	int		count;
	int		temp;

	tab[0] = i;
	tab[1] = k;
	tab[2] = j;
	count = 0;
	while (count < 2)
	{
		if (tab[count] > tab[count + 1])
		{
			temp = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = temp;
			count = 0;
		}
		else
			count++;
	}
	return (tab[1]);
}
