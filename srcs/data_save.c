/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:52:01 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 12:02:48 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	addroom(t_path *p, int id)
{
	t_room	*new;
	t_room	*tmp;

	new = xmalloc(sizeof(*new));
	p->len++;
	new->id = id;
	new->ant = -1;
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

void	save_flux(t_ek *ek, int start, t_path *p)
{
	int		v;

	v = -1;
	if (start == ek->end - 1)
	{
		addroom(p, start);
		if (--ek->depth)
			addpath(p);
		return ;
	}
	while (++v < ek->nb)
	{
		while (p->next)
			p = p->next;
		if (ek->flow[start][v] > 0)
		{
			addroom(p, start);
			save_flux(ek, v, p);
		}
	}
}

t_flux	*addflux(t_ek *e, int len)
{
	t_flux	*new;
	t_flux	*elem;

	new = xmalloc(sizeof(*new));
	new->flux = len;
	new->round = 0;
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
