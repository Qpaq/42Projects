/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:21:51 by dtedgui           #+#    #+#             */
/*   Updated: 2016/03/21 19:22:04 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		is_escape(char *key)
{
	if (key[0] == 27 && key[1] == 0 && key[2] == 0)
		return (1);
	return (0);
}

int		is_return(char *key)
{
	if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		return (1);
	return (0);
}

int		is_space(char *key)
{
	if (key[0] == 32 && key[1] == 0)
		return (1);
	return (0);
}

int		is_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] >= 65 && key[2] <= 68)
		return (1);
	return (0);
}

void	get_key_pressed(t_select *params)
{
	char	*key;

	key = ft_strnew(4);
	while (read(0, key, 3))
	{
		if (is_escape(key))
			break ;
		else if (is_space(key))
			space_key_pressed(params);
		else if (is_return(key))
			return_key_pressed(params);
		else if (is_arrow(key))
			arrow_key_pressed(key[2] - 64, params);
		ft_bzero(key, 4);
	}
}
