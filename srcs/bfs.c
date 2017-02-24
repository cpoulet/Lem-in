/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:36:06 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 19:27:55 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_bfs(t_bfs *b, int n)
{
	b->proc = ft_rangenew(n);
	b->queue = xmalloc(sizeof(t_queue));
	b->tab = xmalloc(sizeof(t_queue) * n);
	queue_init(b->queue, free);
	while (n--)
		queue_init(&(b->tab[n]), free);
}

void	procede(t_lemin *l, t_bfs *b, int k)
{
	(void)l;
	(void)b;
	(void)k;
}

void	bfs(t_lemin *l)
{
	t_bfs	bfs;
	int		*nb;
	int		i;

	init_bfs(&bfs, l->room_nb);
	nb = xmalloc(sizeof(int));
	*nb = l->start - 1;
	enqueue(bfs.queue, nb);
	while (bfs.queue->size != 0)
	{
		dequeue(bfs.queue, (void**)&nb);
		procede(l, &bfs, *nb);
		printf("i = %d\n", *nb);
		i = -1;
		while (++i < l->room_nb)
			if (l->matrix[*nb][i] == '1')
				bfs.proc[i] = 1;
	}
}
