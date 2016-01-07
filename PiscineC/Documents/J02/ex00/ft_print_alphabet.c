/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 13:09:55 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/07 21:16:59 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char debut;
	char fin;

	debut = 'a';
	fin = 'z';
	while (debut <= fin)
	{
		ft_putchar(debut);
		debut++;
	}
}
