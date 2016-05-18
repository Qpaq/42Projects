/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inst_infos2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:49 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 17:03:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op	*return_op_tab(char *name)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (ft_strcmp(g_op_tab[i].name, name) == 0)
			return (&g_op_tab[i]);
		i++;
	}
	return (NULL);
}

int		get_ocp(char **args, char *name)
{
	int		i;
	char	*ocp;
	t_op	*tab;

	tab = return_op_tab(name);
	if (tab && tab->o_cod == 0)
		return (-1);
	i = 0;
	ocp = ft_strnew(8);
	while (args[i])
	{
		(args[i][0] == DIRECT_CHAR) ? ft_strcat(ocp, "10") : NULL;
		(args[i][0] == 'r') ? ft_strcat(ocp, "01") : NULL;
		if (args[i][0] != DIRECT_CHAR && args[i][0] != 'r')
			ft_strcat(ocp, "11");
		i++;
	}
	while (ft_strlen(ocp) < 8)
		ft_strcat(ocp, "00");
	return (ft_atoi_base(ocp, 2));
}
