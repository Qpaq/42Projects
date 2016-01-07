/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:21:20 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/07 12:10:06 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int	parse_format(const char *format, va_list *args)
{
	char	*next_tag;

	next_tag = ft_strchr(format, '%');
	if (next_tag == NULL)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else if (next_tag > format)
	{
		ft_putnstr(format, next_tag - format);
		return (parse_format(next_tag, args));
	}
	else
	{
		ft_putendl("on verra...");
		return (ft_strlen(format));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	if (*format == '\0')
		return (0);
	ret = parse_format(format, &args);
	va_end(args);
	return (ret);
}
