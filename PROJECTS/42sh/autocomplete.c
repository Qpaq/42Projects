/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilla <sguilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 18:22:57 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/21 19:20:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_cmd_path
{
	char				*name;
	struct s_cmd_path	*next;
}				t_cmd_path;

static t_cmd_path	*create_link_cmd_path(char *name, t_cmd_path **head)
{
	t_cmd_path	*new;
	t_cmd_path	*current;

	new = (t_cmd_path *)ft_memalloc(sizeof(t_cmd_path));
	new->name = ft_strdup(name);
	new->next = NULL;
	if (head && *head)
	{
		current = *head;
		while (current)
		{

			current->next = new;
			current = current->next;
		}
	}
	return (new);
}

// IL FAUDRA REMPLACER (char *path) par le PATH dans la liste chainee t_env
int		store_all_cmds(char *path)
{
	DIR				*dirp;
	struct dirent	*file;
	char			*path_array;
	t_cmd_path		*cmds;
	t_cmd_path		*current;

	cmds = NULL;
	path_array = ft_strsplit(path, ":");
	while (*path_array)
	{
		if (!(dirp = opendir(*path_array)))
			return (0);
		while (file = readdir(dirp))
		{
			if (cmds == NULL)
				cmds = create_link_cmd_path(file->d_name, &cmds);
			else
				create_link_cmd_path(file->d_name, &cmds);
		}
		closedir(dirp);
		path_array++;
	}
	return (cmds);
}

char	*autocomplete(t_cmd_path *cmds)
{
	//on parcourt
	//s'il n'y en a qu'un, on renvoit
	//sinon on rnevoit NULL
}

//LE MAIN DU 42SH DEPUIS LEQUEL ON APPELLE store_all_cmds()
int main()
{

	t_cmd_path	*cmds;
	cmds = store_all_cmds("PATH_ENV_VARIABLE");

}
