/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:01:58 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/27 15:34:05 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

// env_variables.c
char		*search_in_env(char *name, t_env *list);
void		change_env_variable(char *name, char *new_value, t_env *list);
int			ft_setenv(char *name, char *value, t_env **head);
int			ft_unsetenv(char *name, t_env *list);
void		print_env(t_env *head);

// commands.c
int			execute_command(char *user_entry, t_env *env_list, char **environ);
char		*find_command(char *command, t_env *env_list);

// builtins.c
void		change_cwd(char **args, t_env *list);
int			builtin_commands(char *name, char **args, t_env *env_list);

#endif
