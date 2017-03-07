/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:55:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 13:57:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	flux_min(t_lemin *l)
{
	t_flux	*flux;
	t_path	*elem;

	flux = l->paths;
	while (flux)
	{
		elem = flux->path;
		flux->min = elem->len;
		while ((elem = elem->next))
			flux->min = elem->len < flux->min ? elem->len : flux->min;
		flux = flux->next;
	}
}

void	move_ant(t_room *r, int n)
{
	int	next;

	if (!r)
		return ;
	next = r->ant;
	r->ant = n;
	move_ant(r->next, next);
}

int		print_out(t_path *p, t_lemin *l, int print)
{
	t_room	*r;
	int		flag;

	flag = 0;
	while (p)
	{
		r = p->first;
		while ((r = r->next))
		{
			if (r->ant >= 0)
			{
				if (print)
					ft_printf("L%d-%s ", r->ant, print_room(l, r->id + 1));
				flag = 1;
			}
		}
		p = p->next;
	}
	if (flag && print)
		write(1, "\n", 1);
	return (flag);
}

void	gogogo(t_lemin *l, t_flux *f, int print)
{
	t_path	*path;
	int		ants;

	l->flag = 1;
	ants = 1;
	while (l->flag)
	{
		path = f->path;
		while (path)
		{
			if (ants > l->ants)
				move_ant(path->first->next, -1);
			else if (f->min == path->len)
				move_ant(path->first->next, ants++);
			else if (path->len - f->min <= l->ants - ants)
				move_ant(path->first->next, ants++);
			else
				move_ant(path->first->next, -1);
			path = path->next;
		}
		l->flag = print_out(f->path, l, print);
		f->round = l->flag ? f->round + 1 : f->round;
	}
	l->flux_to_print = f->round < l->round ? f : l->flux_to_print;
	l->round = f->round < l->round ? f->round : l->round;
}

void	send_ants(t_lemin *l)
{
	t_flux	*flux;

	flux_min(l);
	flux = l->paths;
	while (flux)
	{
		gogogo(l, flux, 0);
		flux = flux->next;
	}
	gogogo(l, l->flux_to_print, 1);
}
