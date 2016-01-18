/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:01:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 17:33:54 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_owner(struct stat infos)
{
	struct passwd	*owner_infos;

	if (!(owner_infos = getpwuid(infos.st_uid)))
		error_message("get_owner()", 1);
	return (owner_infos->pw_name);
}

char		*get_group(struct stat infos)
{
	struct group	*group_infos;

	if (!(group_infos = getgrgid(infos.st_gid)))
		error_message("get_group()", 1);
	return (group_infos->gr_name);
}

char		*get_date(struct stat infos)
{
	char	*time_file;
	char	**time_table_file;
	char	*time_now;
	time_t	now;
	char	**time_table_now;

	now = time(NULL);
	time_now = ctime(&now);
	time_table_now = ft_strsplit(ft_strtrim(time_now), ' ');
	time_file = ft_strtrim(ctime(&(infos.st_mtimespec.tv_sec)));
	time_table_file = ft_strsplit(time_file, ' ');
	if (!ft_strcmp(time_table_now[4], time_table_file[4]))
	{
		time_table_file[3][5] = 0;
		time_file = ft_strjoin_nolimit(' ', time_table_file[1],
				time_table_file[2], time_table_file[3], NULL);
	}
	else
		time_file = ft_strjoin_nolimit(' ', time_table_file[1],
				time_table_file[2], time_table_file[4], NULL);
	ft_memdel((void **)&time_table_now);
	ft_memdel((void **)&time_table_file);
	return (time_file);
}

char		file_type(mode_t file_mode)
{
	if (S_ISDIR(file_mode))
		return ('d');
	else if (S_ISFIFO(file_mode))
		return ('p');
	else if (S_ISCHR(file_mode))
		return ('c');
	else if (S_ISBLK(file_mode))
		return ('b');
	else if (S_ISLNK(file_mode))
		return ('l');
	else if (S_ISSOCK(file_mode))
		return ('s');
	else if (S_ISREG(file_mode))
		return ('-');
	else
		return ('-');
}

char		*file_permissions(mode_t file_mode)
{
	char	*perms;

	perms = ft_strnew(10);
	(file_mode & S_IRUSR) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWUSR) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXUSR) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	(file_mode & S_IRGRP) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWGRP) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXGRP) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	(file_mode & S_IROTH) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWOTH) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXOTH) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	return (perms);
}
