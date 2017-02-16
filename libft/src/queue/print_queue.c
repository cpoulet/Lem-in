/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:14:42 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/16 16:57:14 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_queue(t_queue *q)
{
	int i;

	if (!q)
		return (0);
	if (q->rear == q->front)
	{
		printf("Empty queue !\n");
		return (1);
	}
	printf("Front = %d\n", q->front);
	i = q->front;
	while (i != (q->rear + 1) % q->size)
	{
		printf("%d\n", q->q[i++]);
		i %= q->size;
	}
	printf("Queue = %d\n", q->rear);
	return (1);
}
