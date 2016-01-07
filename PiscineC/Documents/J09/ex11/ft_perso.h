/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 10:11:49 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 10:54:02 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_AUSTIN_POWERS "Save Austin Powers"

struct	s_perso
{
	char	*name;
	double	life;
	int		age;
	char	*profession;
};

typedef struct s_perso	t_perso;

#endif
