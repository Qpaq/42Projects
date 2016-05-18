/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_cor2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:03:01 by dtedgui           #+#    #+#             */
/*   Updated: 2016/05/17 11:57:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*convert_int_to_hex(int val)
{
	char	*tmp;
	char	*res;

	res = ft_itoa_base(val, 16, 0);
	if (ft_strlen(res) == 2)
		return (res);
	tmp = ft_strnew(2);
	tmp[0] = '0';
	tmp[1] = res[0];
	free(res);
	return (tmp);
}

void	write_label_pos(int fd, char *label, t_instruct *cur, t_instruct *head)
{
	int		pos;
	t_op	*tab;

	tab = return_op_tab(cur->instruction);
	pos = 0;
	while (head)
	{
		if (head->label && ft_strcmp(head->label, label) == 0)
		{
			pos = head->position;
			break ;
		}
		head = head->next;
	}
	pos = pos - cur->position;
	write_number(fd, ft_itoa(pos), tab->label_size);
}

long	convert_negative(long nb, int bytes)
{
	long	max;
	int		i;

	if (bytes == 4)
		nb = nb % (256L * 256L * 256L * 256L);
	else if (bytes == 2)
		nb = nb % (256L * 256L);
	i = 0;
	max = 256L * 256L;
	if (bytes == 4)
		max = 256L * 256L * 256L * 256L;
	return (max - nb);
}

long	check_and_convert_number(char *number, int bytes)
{
	long	nb;

	if (number[0] == '-')
	{
		if (ft_strlen(number) >= 20
				&& ft_strcmp(number, ft_ltoa(LONG_MIN)) > 0)
			return (convert_negative(-LONG_MIN, bytes));
	}
	else
	{
		if (ft_strlen(number) >= 19
				&& ft_strcmp(number, ft_ltoa(LONG_MAX)) > 0)
			return (LONG_MAX);
	}
	nb = ft_atol(number);
	if (nb < 0)
		nb = convert_negative(-nb, bytes);
	return (nb);
}

void	write_number(int fd, char *number, int bytes)
{
	int		to_write[4];
	int		i;
	long	nb;

	i = 0;
	nb = check_and_convert_number(number, bytes);
	while (nb > 0 && i < bytes)
	{
		to_write[bytes - 1 - i] = nb % 256;
		nb = nb / 256;
		i++;
	}
	while (i < bytes)
	{
		to_write[bytes - 1 - i] = 0;
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		write(fd, &(to_write[i]), 1);
		i++;
	}
}
