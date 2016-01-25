/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:01:26 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/25 20:45:34 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char		*user_entry;
	char		**commands;
	char		*path;
	pid_t		child;
	extern char	**environ;
	t_env		*env_variables;

	env_variables = store_env_variables(environ);
	while (1)
	{
		write(1, "$>", 2);
		get_next_line(0, &user_entry);
		if (!ft_strcmp(user_entry, "exit"))
			exit(0);
		child = fork();

		ft_putnbr(child);
		ft_putchar('\n');

		if (child == 0)
		{
			commands = ft_strsplit(user_entry, ' ');
			path = ft_strjoin("/bin/", commands[0]);
			execve(path, commands, environ);
		}
		child = wait(&child);

		ft_putnbr(child);
		ft_putchar('\n');
	}
	return (0);
}
