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

int		main(int ac, char **av, char **envp)
{
	char	*user_entry;
	char	**commands;
	char	*path;

	(void)ac;
	(void)av;
	user_entry = NULL;
	while (!ft_strcmp(user_entry, "exit"))
	{
		write(1, "$>", 2);
		get_next_line(0, &user_entry);
		commands = ft_strsplit(user_entry, ' ');
		path = ft_strjoin("/bin/", commands[0]);
		execve(path, commands, envp);
	}
	return (0);
}
