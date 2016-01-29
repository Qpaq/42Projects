/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:12:51 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/29 11:12:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_float(t_tag *tag, va_list *args)
{
	tag->length = 3;
	if (tag->specifier == 'D')
		return (convert_int(tag, args));
	else if (tag->specifier == 'O')
		return (convert_octal(tag, args));
	else if (tag->specifier == 'U')
		return (convert_unsigned_int(tag, args));
	else
		return (-1);
}
