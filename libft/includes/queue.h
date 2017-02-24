/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:31:07 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 16:39:01 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "list.h"

typedef t_list	t_queue;

int		enqueue(t_queue *queue, const void *data);
int		dequeue(t_queue *queue, void **data);
void	queue_init(t_queue *queue, void (*destroy)(void *data));
void	queue_destroy(t_queue *queue);

#endif
