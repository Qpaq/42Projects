/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_kind_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 18:17:53 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/08 00:48:28 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			check_t_ind(char *arg, t_cmd *cmd)
{
	int		i;

	i = (arg[0] == '-') ? 1 : 0;
	while (arg[i] != '\0')
		if (!ft_isdigit(arg[i]))
			ft_error(4, arg, cmd->nl);
		else
			i++;
	return (T_IND);
}

static int			check_t_dir(char *arg, t_cmd *cmd)
{
	int		i;
	char	*label_name;

	i = 0;
	if (arg[i + 1] == LABEL_CHAR && arg[i + 2] != '\0')
	{
		label_name = ft_strsub(arg, i + 2, ft_strlen(arg) - i - 2);
		get_new_label(label_name, A_VERIF, cmd);
		ft_memdel((void **)&label_name);
	}
	else if (ft_isdigit(arg[i + 1]) || (arg[i + 1] == '-'
				&& ft_isdigit(arg[i + 2])))
	{
		i += (arg[i + 1] == '-') ? 1 : 0;
		while (arg[++i] != '\0')
			if (!ft_isdigit(arg[i]))
				ft_error(4, arg, cmd->nl);
	}
	else
		ft_error(9, arg, cmd->nl);
	return (T_DIR);
}

static int			check_t_reg(char *arg, t_cmd *cmd)
{
	int		i;

	i = 1;
	while (arg[i] != '\0')
		if (!ft_isdigit(arg[i]))
			ft_error(4, arg, cmd->nl);
		else
			i++;
	i = ft_atoi(&arg[1]);
	if (!(i >= 0 && i <= REG_NUMBER))
		ft_error(7, arg, cmd->nl);
	return (T_REG);
}

int					get_kind_arg(char *arg, t_cmd *cmd)
{
	int		t_kind;

	t_kind = 0;
	if (ft_isdigit(arg[0]) || ((arg[0] == '-') && ft_isdigit(arg[1])))
		t_kind = check_t_ind(arg, cmd);
	else if (arg[0] == '%')
		t_kind = check_t_dir(arg, cmd);
	else if (arg[0] == 'r')
		t_kind = check_t_reg(arg, cmd);
	else
		ft_error(9, arg, cmd->nl);
	return (t_kind);
}
