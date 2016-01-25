/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:09:40 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/25 20:18:12 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// A SUPPRIMER
void	print_env(t_env *head)
{
	while (head)
	{
		ft_putcolor(head->name, "red");
		ft_putstr("///");
		ft_putcolor(head->value, "green");
		ft_putchar('\n');
		head = head->next;
	}
}

char	*search_in_env(char *name, t_env *list)
{
	t_env	*ptr;

	ptr = list;
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

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
