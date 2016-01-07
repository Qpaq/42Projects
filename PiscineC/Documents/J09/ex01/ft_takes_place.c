/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 06:59:05 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 07:01:44 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	char	*ampm1;
	char	*ampm2;
	int		hour1;
	int		hour2;

	hour1 = hour > 12 ? hour - 12 : hour;
	if (hour == 0)
		hour1 = 12;
	ampm1 = hour < 12 ? "A.M." : "P.M.";
	hour2 = (hour == 0) || (hour == 12) ? 1 : hour + 1;
	hour2 = hour2 > 12 ? hour2 - 12 : hour2;
	if (hour2 == 0)
		hour2 = 12;
	ampm2 = hour == 11 ? "P.M." : ampm1;
	if (hour == 23)
		ampm2 = "A.M.";
	if (hour >= 0 && hour < 24)
		printf("THE FOLLOWING TAKES PLACES BETWEEN %d.00 %s AND %d.00 %s\n",
				hour1, ampm1, hour2, ampm2);
}
