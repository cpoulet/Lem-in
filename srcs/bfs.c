/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:36:06 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/26 17:08:51 by cpoulet          ###   ########.fr       */
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

void	print_q(t_queue *q)
{
	int			i = 0;
	int			*nb;
	t_listelem	*elem;

	printf("[ ");
	elem = q->head;
	while (i++ < q->size)
	{
		nb = elem->data;
		printf("%d ", *nb + 1);
		elem = elem->next;
	}
	printf("]\n");
}

void	print_tab(t_bfs *b)
{
	int	i = 0;

	printf("QUEUE : \t");
	print_q(b->queue);
	while (i < 8)
	{
		printf("%d\t", i + 1);
		print_q(&b->tab[i]);
		i++;
	}
}

void	path_save(t_bfs *b, int k, int nb)
{
	int		*save;
	
	save = xmalloc(sizeof(int));
	*save = k;
	enqueue(&b->tab[nb], save);
}

void	follow_path(t_lemin *l, t_bfs *b, int nb, int len)
{
	int		*old;
	int		*new;
	int		i;

	i = 0;
	if (nb == l->start - 1)
		return ;
	dequeue(&b->tab[nb], (void**)&old);
	while (i++ < len)
	{
		new = xmalloc(sizeof(int));
		*new = *old;
		enqueue(&b->tab[nb], new);
	}
	follow_path(l, b, *old, len);
	free(old);
}

void	procede(t_lemin *l, t_bfs *b, int k)
{
	int		i;
	int		*nb;
	int		*old;
	int		len;

	if (k != l->start - 1)
		dequeue(&b->tab[k], (void**)&old);
	i = -1;
	len = 0;
	while (++i < l->room_nb)
		if (l->matrix[k][i] == 1 && b->proc[i] == 0)
			len++;
	i = -1;
	while (++i < l->room_nb)
	{
		if (l->matrix[k][i] == 1 && b->proc[i] == 0)
		{
			if (k != l->start - 1)
			{
				nb = xmalloc(sizeof(int));
				*nb = *old;
				enqueue(&b->tab[k], nb);
				follow_path(l, b, *nb, len);
			}
			nb = xmalloc(sizeof(int));
			*nb = i;
			enqueue(b->queue, nb);
			path_save(b, k, *nb);
		}
	}
	if (k != l->start - 1)
		free(old);
}

void	print_path(t_lemin *l, t_bfs *b, int nb)
{
	int	*old;

	if (nb == l->start - 1)
	{
		printf("\n%d ", nb + 1);
		return ;
	}
	dequeue(&b->tab[nb], (void**)&old);
	print_path(l, b, *old);
	printf("%d ", nb + 1);
	free(old);
}

void	bfs(t_lemin *l)
{
	t_bfs	bfs;
	int		*nb;

	init_bfs(&bfs, l->room_nb);
	nb = xmalloc(sizeof(int));
	*nb = l->start - 1;
	enqueue(bfs.queue, nb);
	while (bfs.queue->size != 0)
	{
		dequeue(bfs.queue, (void**)&nb);
		if (*nb == l->end - 1)
			print_path(l, &bfs, *nb);
		else
		{
			bfs.proc[*nb] = 1;
			procede(l, &bfs, *nb);
		}
	//	printf("i = %d\n", *nb + 1);
	//	print_tab(&bfs);
		free(nb);
	}
}
