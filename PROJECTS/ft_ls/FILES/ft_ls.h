/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:29 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/29 16:10:56 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h> // le laisser pour perror()

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h> // pour errno
# include <time.h>

//# include <string.h> // strerror

typedef struct	s_file_infos
{
	char				type;
	char				*permissions;
	int					links;
	char				*owner;
	char				*group;
	int					size;
	char				*date;
	char				*name;
	struct s_file_infos	*next;
}				t_file_infos;

typedef struct	s_dir_info
{
	char				*name;
	struct s_dir_info	*next;
}				t_dir_info;

typedef struct	s_ls_args
{
	char		*authorized_options;
	char		*options;
	t_dir_info	*dirs;
}				t_ls_args;

void			check_arguments(int ac, char **av, t_ls_args *ls_args);
int				browse_directories(t_ls_args *args);
void			read_directory(char *dir_name);
t_file_infos	*get_file_info(char *file_name);

#endif
