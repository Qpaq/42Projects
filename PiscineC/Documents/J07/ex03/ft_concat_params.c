/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/14 13:02:27 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/14 14:13:23 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void ft_putstr(char*);

char	*ft_strcpy(char *dest, const char *src)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int		size_dest;
	int		i;

	i = 0;
	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[i] != '\0')
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		iarg;
	char	*str;
	int		sizeargv0;
	int		sizeargv1;

	sizeargv0 = 0;
	sizeargv1 = 0;
	iarg = 2;
	while (*(*argv + sizeargv0) != '\0')
		sizeargv0++;
	while (*(*argv + sizeargv0 + sizeargv1) != '\0')
		sizeargv1++;
	str = malloc(sizeargv1 + 1);
	str = ft_strcpy(str, *argv + sizeargv0);
	while (iarg < argc)
	{
		ft_strcat(str, argv[iarg]);
		iarg++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	ft_putstr(ft_concat_params(argc,argv));
}
