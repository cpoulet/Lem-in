/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:59:48 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 13:18:58 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_destroy(t_list *list)
{
	void	*data;

	while (list->size)
		if (list_rem_next(list, NULL, (void**)&data) == 0 && list->destroy)
			list->destroy(data);
	ft_memset(list, 0, sizeof(list));
}
