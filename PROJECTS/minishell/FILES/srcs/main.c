/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:01:26 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/30 12:42:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*store_env_variables(char **env)
{
	t_env	*head;
	int		i;
	char	*sep;
	char	*name;
	char	*value;

	i = 0;
	head = NULL;
	while (env[i])
	{
		if (!(sep = ft_strchr(env[i], '=')))
			return (NULL);
		name = ft_strndup(env[i], sep - env[i]);
		value = ft_strdup(sep + 1);
		ft_setenv(name, value, &head);
		i++;
	}
	return (head);
}

void	prompt(char **user_entry, t_env *env_list)
{
	char	*user;
	char	*pwd;
	char	*home_dir;

	home_dir = search_in_env("HOME", env_list);
	user = search_in_env("USER", env_list);
	pwd = search_in_env("PWD", env_list);
	if (user && pwd && home_dir)
	{
		pwd = ft_str_replace(pwd, home_dir, "~");
		ft_putcolor(user, "cyan");
		ft_putstr(" in ");
		ft_putcolor(pwd, "light yellow");
		ft_putchar('\n');
	}
	ft_putstr("$> ");
	get_next_line(0, user_entry);
}

void	run_commands(char *user_entry, t_env **env_list, char **environ)
{
	char	**commands;
	char	*command;

	commands = ft_strsplit(user_entry, ';');
	while (*commands)
	{
		command = ft_strtrim(*commands);
		if (ft_strlen(command) != 0)
		{
			if (!execute_command(command, env_list, environ))
			{
				ft_putstr("minishell: command not found: ");
				ft_putendl(*commands);
			}
		}
		commands++;
	}
}

int		main(void)
{
	char		*user_entry;
	extern char	**environ;
	t_env		*env_list;

	env_list = store_env_variables(environ);
	execute_command("clear", &env_list, environ);
	while (1)
	{
		user_entry = NULL;
		while (user_entry == NULL || user_entry[0] == '\0')
			prompt(&user_entry, env_list);
		user_entry = ft_strtrim(user_entry);
		if (ft_strcmp(user_entry, "exit") == 0)
			exit(0);
		run_commands(user_entry, &env_list, environ);
	}
	return (0);
}
