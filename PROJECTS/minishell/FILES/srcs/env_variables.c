/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 20:09:40 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 16:20:42 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// s'affiche a l'appel de "env"
void	print_env(t_env *head)
{
	while (head)
	{
		ft_putstr(head->name);
		ft_putchar('=');
		ft_putstr(head->value);
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

// rajoute une variable d'environnement (setenv)
int		ft_setenv(char *name, char *value, t_env *head)
{
	t_env	*ptr;
	t_env	*new;

	ptr = head;
	while (ptr->next)
	{
		if (ft_strcmp(name, ptr->name) == 0)
		{
			change_env_variable(name, value, head);
			return (1);
		}
	}
	new = (t_env *)ft_memalloc(sizeof(t_env));
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	new->next = NULL;
	ptr->next = new;
}

void	ft_unsetenv(char *name, t_env *list)
{
	t_env	*ptr;
	t_env	*previous;

	ptr = list;
	previous = list;
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
		{
			previous->next = ptr->next;
			break ;
		}
		previous = ptr;
		ptr = ptr->next;
	}
	ft_memdel((void **)&(ptr->name));
	ft_memdel((void **)&(ptr->value));
	ft_memdel((void **)&ptr);
}

void	change_env_variable(char *name, char *new_value, t_env *list)
{
	t_env	*ptr;

	ptr = list;
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
			ptr->value = ft_strdup(new_value);
		ptr = ptr->next;
	}
}
