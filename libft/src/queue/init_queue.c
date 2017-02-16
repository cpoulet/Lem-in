/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 12:00:55 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/16 16:49:50 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	init_queue(t_queue *q, int size, size_t content_size)
{
	if (!q)
		return (0);
	q->front = 0;
	q->rear = 0;
	q->size = size;
	q->q = xmalloc(content_size * size);
	return (1);
}
