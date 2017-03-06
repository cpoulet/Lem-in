/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmondskarp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:01:16 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/06 16:19:06 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_ek(t_lemin *l, t_ek *ek)
{
	ek->flow = ft_tabnew(l->room_nb, l->room_nb);
	ek->par = ft_rangenew(l->room_nb);
	ek->queue = xmalloc(sizeof(t_queue));
	queue_init(ek->queue, free);
	ek->flux = 0;
	ek->nb = l->room_nb;
	ek->end = l->end;
	ek->first = NULL;
}

void	init_bfs_ek(t_lemin *l, t_ek *ek)
{
	int	i;
	int	*nb;

	i = -1;
	while (++i < l->room_nb)
		ek->par[i] = -1;
	ek->par[l->start - 1] = -2;
	queue_destroy(ek->queue);
	nb = xmalloc(sizeof(int));
	*nb = l->start - 1;
	enqueue(ek->queue, nb);
}

void	enqueue_int(t_queue *q, int k)
{
	int	*new;

	new = xmalloc(sizeof(int));
	*new = k;
	enqueue(q, new);
}

int		bfs_ek(t_lemin *l, t_ek *ek)
{
	int v;
	int	*u;

	init_bfs_ek(l, ek);
	while (ek->queue->size)
	{
		dequeue(ek->queue, (void**)&u);
		v = -1;
		while (++v < l->room_nb)
		{
			if ((l->matrix[*u][v] - ek->flow[*u][v]) > 0 && ek->par[v] == -1)
			{
				ek->par[v] = *u;
				if (v != l->end - 1)
					enqueue_int(ek->queue, v);
				else
					return (1);
			}
		}
		free(u);
	}
	return (0);
}

void	printdata(t_ek *e, t_lemin *l)
{
	t_flux	*flux;
	t_path	*path;
	t_room	*room;

	flux = e->first;
	while (flux)
	{
		printf("nbflux = %d :\n", flux->flux);
		path = flux->path;
		while (path)
		{
			printf("path_len = %d\t", path->len);
			room = path->first;
			while (room)
			{
				printf("%s\t", print_room(l, room->id + 1));
				room = room->next;
			}
			path = path->next;
			printf("\n");
		}
		flux = flux->next;
		printf("\n");
	}
	printf("\n");
}

void	edmondskarp(t_lemin *l)
{
	t_ek	ek;
	int		u;
	int		v;
	t_flux	*flux;

	init_ek(l, &ek);
	while (bfs_ek(l, &ek))
	{
		ek.flux++;
		v = l->end - 1;
		while (v != l->start - 1)
		{
			u = ek.par[v];
			ek.flow[u][v]++;
			ek.flow[v][u]--;
			v = u;
		}
		flux = addflux(&ek, ek.flux);
		ek.depth = flux->flux;
		save_flux(&ek, l->start - 1, flux->path);
	}
	l->paths = ek.first;
	printdata(&ek, l);
}
