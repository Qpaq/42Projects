/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:24:11 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/10 15:40:27 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_int(t_tag *tag, va_list *args)
{
	int		output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, int);
	ft_putnbr(output_arg);
}

void	convert_unsigned_int(t_tag *tag, va_list *args)
{
	size_t	output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, size_t);
	ft_putnbr(output_arg);
}

void	convert_octal(t_tag *tag, va_list *args)
{
	int		output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, int);
	ft_itoa_base(output_arg, 8);
}

void	convert_hexa(t_tag *tag, va_list *args)
{
	int		output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, int);
	ft_itoa_base(output_arg, 16);
}

void	convert_char(t_tag *tag, va_list *args)
{
	char	output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, int);
	ft_putchar(output_arg);
}

void	convert_string(t_tag *tag, va_list *args)
{
	char	*output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, char *);
	ft_putstr(output_arg);
}

void	convert_address(t_tag *tag, va_list *args)
{
	int		output_arg;
	(void)tag; //SUPPRIMER
	
	output_arg = va_arg(*args, int);
	ft_putnbr(output_arg);
}
