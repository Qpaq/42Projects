/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:38:19 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/21 19:42:11 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		*convert_list_to_board(t_list *head_list, t_map *map)
{
	int		*tab;
	int		i;

	if (!(tab = (int *)malloc(sizeof(*tab) * (map->number_of_lines + 1))))
		return (NULL);
	i = 0;
	while (head_list)
	{
		if (!head_list->content)
			break ;
		tab[i] = ft_atoi(head_list->content);
		head_list = head_list->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			ft_putendl_fd("ERROR", 2);
			return (0);
		}
		i++;
	}
	if (ft_strlen(line) == 0)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	if (ft_atoi(line) < 1 || ft_atoi(line) > 10000)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	return (1);
}

int				init_game(int fd, t_map *map)
{
	char	*line;
	t_list	*head;
	t_list	*new_link;

	if (!(head = ft_lstnew(NULL, 0)))
		return (0);
	while (get_next_line(fd, &line) && ++(map->number_of_lines))
	{
		if (fd == 0 && ft_strlen(line) == 0 && map->number_of_lines != 1)
			break ;
		if (!check_line(line))
			return (0);
		new_link = ft_lstnew((void *)line, 6);
		ft_lstadd_beginning(&head, new_link);
		map->total_matches += ft_atoi(line);
	}
	map->number_of_lines -= 1;
	map->matches_left = map->total_matches;
	map->board = convert_list_to_board(head, map);
	map->current_line = 0;
	map->current_player = ft_algo(map);
	return (1);
}
