/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ins_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:09:37 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 15:43:07 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_ins_next(t_list *list, t_listelem *elem, const void *data)
{
	t_listelem	*new;

	new = xmalloc(sizeof(t_listelem));
	new->data = (void*)data;
	if (!elem)
	{
		new->next = list->head;
		if (list->size == 0)
			list->tail = new;
		list->head = new;
	}
	else
	{
		if (!elem->next)
			list->tail = new;
		new->next = elem->next;
		elem->next = new;
	}
	list->size++;
	return (0);
}
