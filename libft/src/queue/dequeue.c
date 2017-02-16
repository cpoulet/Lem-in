/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:27:37 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/16 16:55:41 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dequeue(t_queue *q, int *content)
{
	if (!q)
		return (0);
	if (q->front == q->rear)
		return (0);
	q->rear--;
	if (q->rear < 0)
		q->rear = q->size - 1;
	*content = q->q[q->rear];
	return (1);
}
