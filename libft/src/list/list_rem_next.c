/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rem_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:22:06 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 13:47:12 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_rem_next(t_list *list, t_listelem *elem, void **data)
{
	t_listelem	*old;

	if (!list->size)
		return (-1);
	if (!elem)
	{
		old = list->head;
		*data = old->data;
		list->head = old->next;
		list->tail = list->size == 1 ? NULL : list->tail;
	}
	else
	{
		if (!elem->next)
			return (-1);
		*data = elem->next->data;
		old = elem->next;
		elem->next = old->next;
		list->tail = !elem->next ? elem : list->tail;
	}
	free(old);
	list->size--;
	return (0);
}
