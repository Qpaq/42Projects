/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:01:26 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/22 20:38:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main(void)
{
	char		*user_entry;
	char		**commands;
	char		*path;
	pid_t		forked;
	extern char	**environ;

	user_entry = ft_strnew(0);
	write(1, "$>", 2);
	get_next_line(0, &user_entry);
	if (!ft_strcmp(user_entry, "exit"))
		exit(0);
	forked = fork();
//	ft_putstr_array(environ, '\n');
	if (forked > 0)
	{
		commands = ft_strsplit(user_entry, ' ');
		path = ft_strjoin("/bin/", commands[0]);
		execve(path, commands, environ);
	}
	if (forked == 0)
		ft_putcolor("FINI", "red");
	return (0);
}
