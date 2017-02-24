/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:57:24 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/23 15:03:42 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

void	dlist_destroy(t_dlist *list)
{
	void	*data;

	while (list->size)
	{
		if (dlist_remove(list, list->tail, (void **)&data) == 0 &&
				list->destroy != NULL)
			list->destroy(data);
	}
	ft_memset(list, 0, sizeof(t_dlist));
}
