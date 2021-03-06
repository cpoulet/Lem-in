/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:24 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 15:33:11 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*print_room(t_lemin *l, int i)
{
	t_listelem	*elem;

	if (i == 0)
		return (" ");
	elem = l->rooms->head;
	while (--i && elem)
		elem = elem->next;
	return (elem->data);
}

void		init_lemin(t_lemin *l)
{
	l->rooms = xmalloc(sizeof(t_list));
	l->paths = 0;
	l->read = 1;
	l->start = 0;
	l->end = 0;
	l->flag = 0;
	l->room_nb = 0;
	l->ants = 0;
	l->flux_to_print = NULL;
	l->round = ~(1 << 31);
}

void		error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

int			main(void)
{
	t_lemin	l;

	init_lemin(&l);
	parse_lemin(&l);
	if (!l.start || !l.end || l.start == l.end
				|| !l.flag || l.room_nb <= 1)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	ft_printf("\n");
	edmondskarp(&l);
	if (!l.paths)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	send_ants(&l);
	data_free(&l);
	return (0);
}
