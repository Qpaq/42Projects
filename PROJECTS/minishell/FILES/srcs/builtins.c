/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:13:45 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/27 14:48:35 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_cwd(char **args, t_env *list)
{
	char	*pwd;

	pwd = NULL;
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		args[1] = search_in_env("HOME", list);
	if (chdir(args[1]) == 0)
	{
		pwd = getcwd(pwd, 100);
		ft_setenv("PWD", pwd, &list);
	}
	else
		ft_putendl("cd: no such file or directory");
}

int		builtin_commands(char *name, char **args, t_env *env_list)
{
	if (ft_strcmp(name, "cd") == 0)
	{
		change_cwd(args, env_list);
		return (1);
	}
	else if (ft_strcmp(name, "env") == 0)
	{
		print_env(env_list);
		return (1);
	}
	else if (ft_strcmp(name, "setenv") == 0)
	{
		ft_setenv(args[1], args[2], &env_list);
		return (1);
	}
	else if (ft_strcmp(name, "unsetenv") == 0)
	{
		ft_unsetenv(args[1], env_list);
		return (1);
	}
	return (0);
}
