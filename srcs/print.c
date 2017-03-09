/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:18:14 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/09 19:27:26 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	print_start(t_hex *h)
{
	t_print p;

	p.mid = (h->path_nb - 1) < 0 ? 0 : h->path_nb - 1;
	p.top = '-';
	p.bot = '+';
	p.empty = 0;
	p.type = 1;
	p.name = h->start;
	p.next = NULL;
	p.ant = h->ant_nb - h->ant_max;
	p.color = p.ant ? 8 : 0;
	print_box(&p, 1);
}

void	print_end(t_hex *h)
{
	t_print p;

	p.mid = (h->path_nb - 1) < 0 ? 0 : h->path_nb - 1;
	p.top = '+';
	p.bot = '-';
	p.empty = 0;
	p.type = 2;
	p.name = h->end;
	p.next = NULL;
	p.ant = h->ant_out;
	p.color = p.ant ? 8 : 0;
	print_box(&p, 1);
}

t_print	*init_box(t_print *p, t_box *b)
{
	t_print *new;
	t_print	*svg;

	svg = p;
	new = xmalloc(sizeof(t_print));
	new->name = ft_strdup(b->name);
	new->mid = 0;
	new->empty = 0;
	new->type = 0;
	new->top = '+';
	new->bot = '+';
	new->ant = b->ant;
	new->color = b->ant ? b->ant % 5 + 1 : 0;
	new->next = NULL;
	if (p)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	else
		p = new;
	return (svg ? svg : new);
}

t_print	*empty_box(t_print *p, t_box *b)
{
	t_print *new;
	t_print *svg;

	svg = p;
	new = xmalloc(sizeof(t_print));
	if (b)
		new->name = ft_strdup(b->name);
	else
		new->name = ft_strdup("EMPTY");
	new->mid = 0;
	new->empty = 1;
	new->type = 0;
	new->next = NULL;
	if (p)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	else
	{
		p = new;
		svg = p;
	}
	return (svg);
}
