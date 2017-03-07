/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:40:18 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 15:27:07 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	path_free(t_path *p)
{
	t_path	*tmp;
	t_room	*r;
	t_room	*tmp_r;

	while (p)
	{
		tmp = p->next;
		p->len = 0;
		r = p->first;
		while (r)
		{
			tmp_r = r->next;
			r->id = 0;
			r->ant = 0;
			free(r);
			r = tmp_r;
		}
		free(p);
		p = tmp;
	}
}

void	flux_free(t_flux *f)
{
	t_flux	*tmp;

	while (f)
	{
		tmp = f->next;
		f->flux = 0;
		f->min = 0;
		f->round = 0;
		path_free(f->path);
		free(f);
		f = tmp;
	}
}

void	matrix_free(char **f, int i)
{
	while (i--)
		free(f[i]);
	free(f);
}

void	ek_free(t_ek *ek)
{
	queue_destroy(ek->queue);
	free(ek->par);
	free(ek->queue);
	matrix_free(ek->flow, ek->nb);
}

void	data_free(t_lemin *l)
{
	flux_free(l->paths);
	list_destroy(l->rooms);
	matrix_free(l->matrix, l->room_nb);
	free(l->rooms);
}
