/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:01:26 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 16:09:37 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env_variable(char *env)
{
	t_env	*new;
	char	*sep;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	if (!(sep = ft_strchr(env, '=')))
		return (NULL);
	new->name = ft_strndup(env, sep - env);
	new->value = ft_strdup(sep + 1);
	new->next = NULL;
	return (new);
}

t_env	*store_env_variables(char **env)
{
	t_env	*head;
	t_env	*ptr;
	int		i;

	head = new_env_variable(env[0]);
	i = 1;
	ptr = head;
	while (env[i])
	{
		ptr->next = new_env_variable(env[i]);
		ptr = ptr->next;
		i++;
	}
	return (head);
}

void	prompt(char **user_entry, t_env *env_list)
{
	char	*user;
	char	*cwd;

	user = search_in_env("USER", env_list);
	cwd = search_in_env("PWD", env_list);
	ft_putcolor(user, "cyan");
	ft_putstr(" in ");
	ft_putcolor(cwd, "light yellow");
	ft_putstr(" $>");
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
