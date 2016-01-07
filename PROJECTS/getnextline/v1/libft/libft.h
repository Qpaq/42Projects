/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:42 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/28 17:08:37 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
char		*ft_strncpy(char *dst, const char *src, size_t n);
void		ft_bzero(void *s, size_t n);
void		ft_putendl(const char *s);

#endif
