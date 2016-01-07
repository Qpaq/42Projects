/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/20 15:43:47 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/21 13:07:00 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 32000

void	ft_tail(char *file, int output_size);
int		ft_atoi(char *str);

#endif
