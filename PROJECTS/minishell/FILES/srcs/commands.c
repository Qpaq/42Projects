/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:27:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/30 12:41:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command(char *command, t_env *env_list)
{
	char			**path_array;
	DIR				*dirp;
	struct dirent	*file;

	if (!search_in_env("PATH", env_list))
		return (NULL);
	path_array = ft_strsplit(search_in_env("PATH", env_list), ':');
	while (*path_array)
	{
		*path_array = ft_strjoin(*path_array, "/");
		if (ft_strstr(command, *path_array))
			command = ft_str_replace(command, *path_array, "");
		if (!(dirp = opendir(*path_array)))
			return (NULL);
		while ((file = readdir(dirp)))
		{
			if (ft_strcmp(file->d_name, command) == 0)
				return (ft_strjoin(*path_array, file->d_name));
		}
		closedir(dirp);
		path_array++;
	}
	return (NULL);
}

int		execute_command(char *user_entry, t_env **env_list, char **environ)
{
	char		*path;
	pid_t		child;
	char		**command;
	int			i;

	i = 0;
	command = ft_strsplit(user_entry, ' ');
	while (command[i])
	{
		command[i] = ft_strtrim(command[i]);
		i++;
	}
	if (builtin_commands(command[0], command, env_list))
		return (1);
	if (!(*env_list))
		return (0);
	if ((path = find_command(ft_tolower(command[0]), *env_list)))
		child = fork();
	else
		return (0);
	if (child == 0)
		execve(path, command, environ);
	child = wait(&child);
	return (1);
}
