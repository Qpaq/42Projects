/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:13:22 by exam              #+#    #+#             */
/*   Updated: 2015/08/07 18:31:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	boucle(int alphabet, char majuscule, char minuscule)
{
	while (alphabet < 26)
	{
		if (alphabet % 2 == 0)
		{
			write(1, &minuscule, 1);
			minuscule -= 2;
			alphabet++;
		}
		else
		{
			write(1, &majuscule, 1);
			majuscule -= 2;
			alphabet++;
		}
	}
}

int		main(void)
{
	int		alphabet;
	char	majuscule;
	char	minuscule;
	char	retour_ligne;

	alphabet = 0;
	majuscule = 'Y';
	minuscule = 'z';
	retour_ligne = '\n';
	boucle(alphabet, majuscule, minuscule);
	write(1, &retour_ligne, 1);
	return (0);
}
