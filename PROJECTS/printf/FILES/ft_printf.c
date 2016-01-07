/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:21:20 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/07 14:13:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_arg(char **format)
{
	int		ret;

	ret = 0;
	while (**format && **format != ' ')
	{
		ret++;
		ft_putchar(**format);
		(*format)++;
	}
	return (ret);
}

static int	parse_format(const char *format, va_list *args, int ret)
{
	char	*next_tag;
	int		handler_size;

	next_tag = ft_strchr(format, '%');
	if (next_tag == NULL)
	{
		ft_putstr(format);
		return (ret + ft_strlen(format));
	}
	else if (next_tag > format)
	{
		ft_putnstr(format, next_tag - format);	
		return (parse_format(next_tag, args, ret + (next_tag - format)));
	}
	else
	{
		handler_size = process_arg((char **)&format);
		return (parse_format(format, args, ret + handler_size));
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	if (*format == '\0')
		return (0);
	ret = parse_format(format, &args, 0);
	va_end(args);
	return (ret);
}
