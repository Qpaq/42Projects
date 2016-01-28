/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 09:33:18 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/08 12:53:49 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAG_STRUCT_H
# define TAG_STRUCT_H

/*
** TAG FORMAT
** %[flags][width][.precision][length]specifier
** http://www.pixelbeat.org/programming/gcc/format_specs.html
*/
typedef struct		s_tag
{
	/* SPECIFIER */
	char	specifier;

	/* FLAGS (booleans) */
	char	flag_minus;
	char	flag_plus;
	char	flag_space;
	char	flag_sharp;
	char	flag_zero;

	/* WIDTH */
	char	has_width;
	int		width;

	/* PRECISION */
	char	has_precision;
	int		precision;

	/* LENGTH 
	 * Peut prendre des valeurs de 0 a 6 :
		0 none
		1 h
		2 hh
		3 l
		4 ll
		5 j
		6 z
	*/
	char	length;
}					t_tag;

#endif
