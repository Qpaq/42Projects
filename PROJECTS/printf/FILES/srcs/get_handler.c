/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:38:54 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/10 15:38:56 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_valid_specifier(char c)
{
	char	*authorized;

	authorized = "sSpdDioOuUxXcC";
	if (!ft_strchr(authorized, c))
		return (0);
	return (1);
}

void	(*return_handler(char c))(t_tag *, va_list *)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (&convert_int);
	else if (c == 'u' || c == 'U')
		return (&convert_unsigned_int);
	else if (c == 'o' || c == 'O')
		return (&convert_octal);
	else if (c == 'x' || c == 'X')
		return (&convert_hexa);
	else if (c == 'c' || c == 'C')
		return (&convert_char);
	else if (c == 's' || c == 'S')
		return (&convert_string);
	else if (c == 'p')
		return (&convert_address);
	else
		return (NULL);
}
