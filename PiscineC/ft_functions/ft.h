/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 12:59:23 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/24 22:39:11 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strrev(char *str);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(char *src);

char	*ft_strcapitalize(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strlowcase(char *str);
char	*ft_strupcase(char *str);

int		ft_atoi(char *str);
char	*ft_itoa(int nb);

void	ft_putnbr(int nb);
void	ft_sort_integer_table(int *tab, int size);
int		ft_sqrt(int nb);

int		ft_power(int number, int power);
void	ft_swap(int *a, int *b);

int		*ft_range(int min, int max);

#endif
