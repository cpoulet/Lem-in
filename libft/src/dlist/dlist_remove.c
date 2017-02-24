/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:10:41 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/23 16:17:39 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

int	dlist_remove(t_dlist *list, t_dlistelem *elem, void **data)
{
	if (!elem || !list->size)
		return (-1);
	*data = elem->data;
	if (elem == list->head)
	{
		list->head = elem->next;
		if (!elem->next)
			list->tail = NULL;
		else
			elem->next->prev = NULL;
	}
	else
	{
		elem->prev->next = elem->next;
		if (!elem->next)
			list->tail = elem->prev;
		else
			elem->next->prev = elem->prev;
	}
	free(elem);
	list->size--;
	return (0);
}
