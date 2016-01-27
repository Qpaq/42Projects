/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:27:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/27 18:29:22 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command(char *command, t_env *env_list)
{
	char			**path_array;
	char			*path;
	DIR				*dirp;
	struct dirent	*file;

	if (!env_list)
		return (NULL);
	path_array = ft_strsplit(search_in_env("PATH", env_list), ':');
	while (*path_array)
	{
		dirp = opendir(*path_array);
		while ((file = readdir(dirp)))
		{
			if (ft_strcmp(file->d_name, command) == 0)
			{
				path = ft_strjoin_nolimit(0,
						*path_array, "/", file->d_name, NULL);
				return (path);
			}
		}
		closedir(dirp);
		path_array++;
	}
	return (NULL);
}

int		execute_command(char *user_entry, t_env *env_list, char **environ)
{
	char		*path;
	pid_t		child;
	char		**command;

	command = ft_strsplit(user_entry, ' ');
	if (builtin_commands(command[0], command, env_list))
		return (1);
	if ((path = find_command(ft_tolower(command[0]), env_list)))
		child = fork();
	else
		return (0);
	if (child == 0)
		execve(path, command, environ);
	child = wait(&child);
	return (1);
}
