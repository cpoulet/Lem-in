/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:55:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/06 18:33:40 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		tmp_calculate(t_lemin *l, t_flux *flux)
{
	t_path	*elem;
	int		tmp;
	int		rest;

	elem = flux->path;
	flux->min = elem->len;
	while ((elem = elem->next))
		flux->min = elem->len < flux->min ? elem->len : flux->min;
	elem = flux->path;
	rest = elem->len - flux->min;
	while ((elem = elem->next))
		rest += elem->len - flux->min;
	tmp = flux->min - 2 + l->ants / flux->flux;
	tmp += (l->ants % flux->flux + rest) / flux->flux;
	tmp += (l->ants % flux->flux + rest) % flux->flux;
	return (tmp);
}

int		flux_max(t_lemin *l)
{
	int		tmp;
	int		n;
	int		value;
	t_flux	*flux;

	flux = l->paths;
	n = 1;
	while (flux)
	{
		if (flux->flux == 1)
			tmp = l->ants + flux->path->len - 2;
		else
		{
			value = tmp_calculate(l, flux);
			if (value < tmp)
			{
				n = flux->flux;
				tmp = value;
			}
		}
		flux = flux->next;
	}
	return (n);
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

int		print_out(t_path *p, t_lemin *l)
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
				ft_printf("L%d-%s ", r->ant, print_room(l, r->id + 1));
				flag = 1;
			}
		}
		p = p->next;
	}
	write(1, "\n", 1);
	return (flag);
}

void	gogogo(t_lemin *l, t_flux *f)
{
	t_path	*path;
	int		ants;
	int		n;

	n = 1;
	ants = 1;
	while (n)
	{
		path = f->path;
		while (path)
		{
			if (ants > l->ants)
				move_ant(path->first->next, -1);
			else if (f->min == path->len)
				move_ant(path->first->next, ants++);
			else if (path->len - f->min > l->ants - ants)
				move_ant(path->first->next, ants++);
			path = path->next;
		}
		n = print_out(f->path, l);
	}
}

void	send_ants(t_lemin *l)
{
	t_flux	*flux;

	flux_max(l);
	flux = l->paths;
	while (flux->next)
		flux = flux->next;
	gogogo(l, flux);
}
