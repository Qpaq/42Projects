/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 08:56:49 by alhote            #+#    #+#             */
/*   Updated: 2015/08/23 20:36:24 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle.h"

char		*add_letter_to_str(char *dest, char letter, int size)
{
	int		size_dest;
	int		i;
	char	*tmp;

	i = 0;
	size_dest = 0;
	tmp = (char*)malloc((size + 1) * sizeof(char));
	while (dest != NULL && dest[size_dest] != '\0')
	{
		tmp[size_dest] = dest[size_dest];
		size_dest++;
	}
	tmp[size_dest] = letter;
	tmp[size_dest + 1] = '\0';
	return (tmp);
}

char		*copy_stdin(void)
{
	char	*str;
	char	letter;
	int		size;
	char	*tmp;

	size = 1;
	tmp = NULL;
	str = NULL;
	while (read(0, &letter, 1))
	{
		str = add_letter_to_str(tmp, letter, size++);
		free(tmp);
		tmp = str;
	}
	return (str);
}

int			main(void)
{
	char	*rectangle;

	rectangle = copy_stdin();
	if (rectangle == 0)
	{
		ft_putstr(MSG_ERREUR);
		return (0);
	}
	colle(rectangle);
	return (0);
}
