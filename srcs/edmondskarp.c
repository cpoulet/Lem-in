/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmondskarp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:01:16 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/01 12:31:13 by cpoulet          ###   ########.fr       */
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

void	enqueue_int(t_queue *q, int	k)
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

void	addroom(t_path *p, int id)
{
	t_room	*new;
	t_room	*tmp;

	new = xmalloc(sizeof(*new));
	p->len++;
	new->id = id;
	new->next = NULL;
	if (p->first)
	{
		tmp = p->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		p->first = new;
}

void	addpath(t_path *p)
{
	t_path	*new;

	new = xmalloc(sizeof(*new));
	new->len = 0;
	new->next = NULL;
	new->first = NULL;
	while (p->next)
		p = p->next;
	p->next = new;
}

void	print_flux(t_lemin *l, t_ek *ek, int start, t_path *p, int k)
{
	int		v;

	v = -1;
	if (start == l->end - 1)
	{
		addroom(p, start);
		k--;
		if (k)
			addpath(p);
		printf("0\n");
		return ;
	}
	while (++v < l->room_nb)
	{
		while (p->next)
			p = p->next;
		if (ek->flow[start][v] > 0)
		{
			addroom(p, start);
			printf("%d ", start + 1);
			print_flux(l, ek, v, p, k);
		}
	}
}

t_flux	*addflux(t_ek *e, int len)
{
	t_flux	*new;
	t_flux	*elem;

	new = xmalloc(sizeof(*new));
	new->flux = len;
	new->path = xmalloc(sizeof(t_path));
	new->path->len = 0;
	new->path->first = NULL;
	new->path->next = NULL;
	new->next = NULL;
	if (e->first)
	{
		elem = e->first;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		e->first = new;
	return (new);
}

void	printdata(t_ek *e)
{
	t_flux	*flux;
	t_path	*path;
	t_room	*room;

	flux = e->first;
	while (flux)
	{
		printf("nbflux = %d\t", flux->flux);
		path = flux->path;
		while (path)
		{
			printf("path_len = %d\t", path->len);
			room = path->first;
			while (room)
			{
				printf("room_id = %d ", room->id + 1);
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
	printf("nb flux = %d\n", ek.flux);
	print_flux(l, &ek, l->start - 1, flux->path, flux->flux);
	//printdata(&ek);
	}
}
