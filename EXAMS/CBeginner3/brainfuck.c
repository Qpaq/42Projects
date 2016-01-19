/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:53:47 by exam              #+#    #+#             */
/*   Updated: 2016/01/12 11:27:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*init_ptr(void)
{
	char	*ptr;
	int		i;

	i = 2048;
	ptr = (char *)malloc(sizeof(char) * 2049);
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}

void	interpreter(char *str)
{
	char	*ptr;
	char	*str_start;
	char	*loop_start;

	ptr = init_ptr();
	str_start = str;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[')
		{
			loop_start = str;
			if (*ptr == 0)
			{
				while (*str && *str != ']')
					str++;
			}
		}
		else if (*str == ']')
		{
			if (*ptr != 0)
				str = loop_start;
		}
		str++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		interpreter(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
