/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:22:10 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/10 15:37:33 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "tag_struct.h"

int		ft_printf(const char *format, ...);

void	get_flags(char **format, t_tag *tag);
void	get_width(char **format, t_tag *tag);
void	get_precision(char **format, t_tag *tag);
void	get_length(char **format, t_tag *tag);
void	get_specifier(char **format, t_tag *tag);

int		is_valid_specifier(char c);
void	(*return_handler(char c))(t_tag *, va_list *);

void	convert_int(t_tag *tag, va_list *args);
void	convert_unsigned_int(t_tag *tag, va_list *args);
void	convert_octal(t_tag *tag, va_list *args);
void	convert_hexa(t_tag *tag, va_list *args);
void	convert_char(t_tag *tag, va_list *args);
void	convert_string(t_tag *tag, va_list *args);
void	convert_address(t_tag *tag, va_list *args);

#endif
