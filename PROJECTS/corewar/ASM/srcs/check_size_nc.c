/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_nc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbunel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:15:55 by kbunel            #+#    #+#             */
/*   Updated: 2016/05/11 17:24:24 by kbunel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		check_size_nc(t_cmd *cmd)
{
	if (ft_strlen(cmd->name) > PROG_NAME_LENGTH - 4)
		ft_error(10, NAME_CMD_STRING, cmd->nl);
	else if (ft_strlen(cmd->comment) > COMMENT_LENGTH - 10)
		ft_error(10, COMMENT_CMD_STRING, cmd->nl);
}
