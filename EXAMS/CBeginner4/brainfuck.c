/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:34:11 by exam              #+#    #+#             */
/*   Updated: 2016/01/19 12:55:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*init_ptr(void)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * 2050);
	i = 0;
	while (i < 2050)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	brainfuck(char *string)
{
	char	*ptr;
	int		loop;

	ptr = init_ptr();
	while (*string)
	{
		if (*string == '>')
			ptr++;
		else if (*string == '<')
			ptr--;
		else if (*string == '+')
			(*ptr)++;
		else if (*string == '-')
			(*ptr)--;
		else if (*string == '.')
			write(1, ptr, 1);
		else if (*string == '[')
		{
			if (*ptr == 0)
			{
				string++;
				loop = 1;
				while (*string && loop > 0)
				{
					if (*string == '[')
						loop++;
					if (*string == ']')
						loop--;
					string++;
				}
			}
		}
		else if (*string == ']')
		{
			if (*ptr != 0)
			{
				string--;
				loop = 1;
				while (*string && loop > 0)
				{
					if (*string == ']')
						loop++;
					if (*string == '[')
						loop--;
					string--;
				}
			}
		}
		string++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
