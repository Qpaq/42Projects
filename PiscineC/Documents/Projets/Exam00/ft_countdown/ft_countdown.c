/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:02:50 by exam              #+#    #+#             */
/*   Updated: 2015/08/07 18:08:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	char	number;
	char	newline;

	newline = '\n';
	number = '9';
	while (number >= '0')
	{
		write(1, &number, 1);
		number--;
	}
	write(1, &newline, 1);
	return (0);
}
