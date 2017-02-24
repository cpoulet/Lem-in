/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_ins_prev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:54:04 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/23 16:18:05 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	dlist_ins_prev(t_dlist *list, t_dlistelem *elem, const void *data)
{
	t_dlistelem	*new;

	if (!elem && !list->size)
		return (-1);
	new = xmalloc(sizeof(t_dlistelem));
	new->data = (void *)data;
	if (list->size == 0)
	{
		list->head = new;
		list->tail = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		new->prev = elem->prev;
		new->next = elem;
		if (!elem->prev)
			list->head = new;
		else
			elem->prev->next = new;
		elem->prev = new;
	}
	list->size++;
	return (0);
}
