/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:00:44 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/13 18:50:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "ft_printf.h"
# include "op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

enum
{
	A_VERIF,
	IS_LABEL
};

typedef struct		s_label
{
	char			*name;
	int				kind;
	struct s_label	*next;
}					t_label;

typedef struct		s_cmd
{
	int				v_name;
	int				l_name;
	char			*name;
	int				v_comment;
	int				l_comment;
	char			*comment;
	int				nc;
	int				nl;
	int				nb_instr;
	t_label			*label;
}					t_cmd;

void				parse_file(char		*champ);
void				init(t_cmd *cmd);
void				free_cmd(t_cmd *cmd);
void				ft_error(int error, char *txt, int nl);
void				check_nc(char *line, t_cmd *cmd);
void				check_size_nc(t_cmd *cmd);
int					line_kind(char	*line);
void				check_instr(char *line, int opcode, t_cmd *cmd);
void				get_new_label(char *name, int kind, t_cmd *cmd);
int					get_kind_arg(char *arg, t_cmd *cmd);
void				check_label(char *line, t_cmd *cmd);
void				check_label_connections(t_cmd *cmd);
void				end_nc(t_cmd *cmd);

/*
** get_cor_file.c
*/
void				error_exit(char *message);
void				get_cor_file(char *arg);
char				*check_file_name(char *arg);

/*
** header.c
*/
int					get_header(int fd, t_header *header);
int					is_name(char *line);
int					is_comment(char *line);

/*
** get_instructions.c
*/
int					get_instructions(int fd, t_instruct **instruct);
int					line_has_label(char *line);
void				add_instruction_to_list(char *line, t_instruct **instruct);
void				strip_comments(char **line);

/*
** write_to_cor.c
*/
void				write_to_cor(char *name, t_header *header,
						t_instruct *instruct);
void				write_header(int fd, t_header *header,
						t_instruct *instruct);
void				write_instruction(int fd, t_instruct *instruct,
						t_instruct *head);
void				write_args(int fd, t_instruct *current, char **args,
						t_instruct *head);
void				write_magic(int fd, unsigned int magic);
void				write_number(int fd, char *number, int bytes);
void				write_label_pos(int fd, char *label, t_instruct *cur,
						t_instruct *head);
char				*convert_int_to_hex(int val);
void				write_string_to_file(int fd, char *str, int size);

/*
** get_inst_infos.c
*/
char				*get_inst_label(char **line);
char				*get_inst_name(char **line);
char				**get_inst_args(char *line);
int					get_inst_size(char **args, t_instruct *current);
int					get_ocp(char **args, char *name);
t_op				*return_op_tab(char *name);
int					get_ocp(char **args, char *name);

#endif
