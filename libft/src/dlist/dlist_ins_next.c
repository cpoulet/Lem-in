/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_ins_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:04:47 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/23 16:18:16 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	dlist_ins_next(t_dlist *list, t_dlistelem *elem, const void *data)
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
		new->next = elem->next;
		new->prev = elem;
		if (!elem->next)
			list->tail = new;
		else
			elem->next->prev = new;
		elem->next = new;
	}
	list->size++;
	return (0);
}
