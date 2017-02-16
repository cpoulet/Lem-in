/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:27:37 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/16 17:04:00 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	enqueue(t_queue *q, int content)
{
	if (!q || !content)
		return (0);
	if ((q->rear + 1) % q->size == q->front)
		return (0);
	q->front--;
	if (q->front < 0)
		q->front = q->size - 1;
	q->q[q->front] = content;
	return (1);
}
