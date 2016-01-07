/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:42 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/18 11:19:43 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 10

typedef struct		s_list_gnl
{
	int					fd;
	char				*temp;
	struct s_list_gnl	*next;
}					t_list_gnl;

int					get_next_line(int const fd, char **line);

void				ft_putchar(char c);
void				ft_putendl(char const *s);

size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);

void				ft_bzero(void *s, size_t n);
char				*ft_strnew(size_t size);

#endif
