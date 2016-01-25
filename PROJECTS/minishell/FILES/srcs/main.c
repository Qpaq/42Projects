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

// returns the path if found, NULL otherwise
char	*find_command(char *command, t_env *env_list)
{
	char			**path_array;
	char			*path;
	DIR				*dirp;
	struct dirent	*file;

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
	if ((path = find_command(command[0], env_list)))
		child = fork();
	else
		return (0);
	if (child == 0)
		execve(path, command, environ);
	child = wait(&child);
	return (1);
}

void	prompt(char **user_entry, t_env *env_list)
{
	char	*user;
	char	*cwd;

	user = search_in_env("USER", env_list);
	cwd = search_in_env("PWD", env_list);
	ft_putstr(user);
//	ft_putchar(':');
//	ft_putstr(cwd);
	ft_putstr("$>");
	get_next_line(0, user_entry);
}

int		main(void)
{
	char		*user_entry;
	extern char	**environ;
	t_env		*env_list;

	env_list = store_env_variables(environ);
	while (1)
	{
		user_entry = NULL;
		while (user_entry == NULL || user_entry[0] == '\0')
			prompt(&user_entry, env_list);
		if (ft_strcmp(user_entry, "exit") == 0)
			exit(0);
		if (!execute_command(user_entry, env_list, environ))
			ft_putendl("erreur de commande");
	}
	return (0);
}
