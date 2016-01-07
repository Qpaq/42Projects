/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 14:32:32 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/06 22:20:17 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char debut;
	char fin;

	debut = 'z';
	fin = 'a';
	while (debut >= fin)
	{
		ft_putchar(debut);
		debut--;
	}
}
