/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:54:01 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:51:20 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_octal(t_tag *tag, va_list *args)
{
	uintmax_t		output_arg;

	output_arg = va_arg(*args, uintmax_t);
	output_arg = get_unsigned_length(output_arg, tag);
	if (output_arg == 0 && tag->has_precision && !tag->flag_sharp
		&& (tag->precision == 1 || tag->precision == 0))
		return (tag->precision = 0);
	if (tag->has_precision == 1)
		return (print_uint(tag, output_arg, "01234567", NULL));
	else
		return (print_uint(tag, output_arg, "01234567", "0"));
}
