/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:02:23 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 20:24:07 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_option(char *arg, t_ls_args *ls_args)
{
	while (*arg)
	{
		if (!ft_strchr(ls_args->authorized_options, *arg) || !ft_isalnum(*arg))
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			ft_putstr("usage: ls [-");
			ft_putstr(ls_args->authorized_options);
			ft_putendl("] [file ...]");
			exit(0);
		}
		arg++;
	}
	return (1);
}

static int	store_requested_dir(char *dir_name, t_ls_args *ls_args)
{
	t_files			*new_dir;

	if (!(new_dir = get_file_info(dir_name, 0)))
		return (0);
	if (new_dir->type != 'd')
	{
		if (new_dir->type == 'l' && !ft_strchr(ls_args->options, 'l'))
		{
			if (!(new_dir = get_file_info(dir_name, 1)))
				return (0);
		}
		else
		{
			print_file(new_dir, ls_args, 0, 0);
			return (1);
		}
	}
	lst_add_end(&(ls_args->dirs), new_dir);
	return (1);
}

static void	modify_options(char **options)
{
	char	*tmp;

	if (ft_strchr(*options, 'g'))
	{
		tmp = ft_strjoin(*options, "l");
		ft_memdel((void **)options);
		*options = ft_strdup(tmp);
	}
	if (ft_strchr(*options, 'f'))
	{
		tmp = ft_strjoin(*options, "a");
		ft_memdel((void **)options);
		*options = ft_strdup(tmp);
	}
}

void		check_arguments(int ac, char **av, t_ls_args *ls_args)
{
	int			i;
	char		*args_list;

	i = 0;
	args_list = ft_strnew(2);
	while (++i < ac && av[i][0] == '-' && is_option(&av[i][1], ls_args))
	{
		args_list = ft_mem_realloc(args_list,
				ft_strlen(args_list) + ft_strlen(av[i]));
		args_list = ft_strcat(args_list, &av[i][1]);
	}
	modify_options(&args_list);
	ls_args->options = ft_strdup(args_list);
	ft_memdel((void **)&args_list);
	if (i == ac)
		store_requested_dir(".", ls_args);
	while (i < ac)
	{
		if (!store_requested_dir(av[i], ls_args))
			print_error(av[i], 1);
		i++;
	}
}
