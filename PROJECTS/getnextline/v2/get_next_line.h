/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:35:45 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/29 15:24:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 99

# include <fcntl.h>
# include "libft/includes/libft.h"

int					get_next_line(int const fd, char **line);

typedef struct		s_list_gnl
{
	int					fd;
	char				*temp;
	struct s_list_gnl	*next;
}					t_list_gnl;

#endif
