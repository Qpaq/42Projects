/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 12:57:37 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 13:02:58 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree		*new_elem;

	new_elem = (t_btree*)malloc(sizeof(t_btree));
	new_elem->left = NULL;
	new_elem->right = NULL;
	new_elem->data = item;
	return (new_elem);
}
