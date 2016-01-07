/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:42 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/29 14:40:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnew(size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
void		ft_memdel(void **ap);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
