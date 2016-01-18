/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:42 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 19:59:26 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

/*
** PRINTING
*/
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putnstr(char const *s, size_t n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putcolor(char *str, char *color);
void			ft_putrainbow(char *str);

void			ft_putstr_array(char **array, char sep);

void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base(int n, int base);

/*
** NUMBERS
*/
int				ft_atoi(char *nb);
int				ft_atoi_base(char *nb, int base);
char			*ft_itoa(int nb);
char			*ft_itoa_base(int n, int base);
int				ft_power(int nb, int pow);
void			ft_sort_integer_table(int *tab, int size);

/*
** STRINGS
*/
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);

size_t			ft_strlen(const char *s);
size_t			ft_strlen_char(const char *s, char c);

void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_nolimit(char delimiter, char *s1, ...);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrev(char *str);

int				ft_strcount(char *str, char to_find);

/*
** MEMORY
*/
void			*ft_memset(void *str, int src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_mem_realloc(char *old, size_t size);

#endif
