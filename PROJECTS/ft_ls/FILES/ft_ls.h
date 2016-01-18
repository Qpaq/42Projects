/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:29 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 19:58:51 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_files
{
	dev_t				device;
	char				type;
	char				*permissions;
	int					links;
	char				*owner;
	char				*group;
	int					size;
	int					blocks;
	char				*date;
	unsigned int		timestamp;
	char				*name;
	char				*parent_dir;
	struct s_files		*next;
}				t_files;

typedef struct	s_ls_args
{
	char		*authorized_options;
	char		*options;
	t_files		*dirs;
}				t_ls_args;

void			check_arguments(int ac, char **av, t_ls_args *ls_args);
void			browse_directories(t_ls_args *args);
t_files			*get_file_info(char *file_name, char is_link);

char			*file_permissions(mode_t file_mode);
char			file_type(mode_t file_mode);
char			*get_date(struct stat infos);
char			*get_group(struct stat infos);
char			*get_owner(struct stat infos);

void			lst_add_end(t_files **head, t_files *new);
void			lst_insert_after(t_files *target, char *new);
void			concat_list(t_files *target, t_files *new);
t_files			*lst_copy_link(t_files *link);
t_files			*sort_from_options(t_files *head, char *options, char by_name);

void			print_dir(t_files *head, char *dir_name, t_ls_args *args);
void			print_file(t_files *file, t_ls_args *args, int links, int size);
int				get_length_column(t_files *head, char field);
void			pad_with_spaces(t_files *file, int size, char field);
int				get_total_size(t_files *head);
void			add_color(t_files *file);

void			print_error(char *message, int time);
void			error_message(char *message, int terminate);

void			free_one(t_files *head);
void			free_list(t_files *head);
void			free_main_struct(t_ls_args *args);

#endif
