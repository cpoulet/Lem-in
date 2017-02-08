/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:46:54 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 18:18:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		isintab(t_lemin *l, int i)
{
	int k;

	k = -1;
	while (++k < l->room_nb)
		if (i == l->tab[k])
			return (0);
	return (1);
}
/*
static void		print_path(t_lemin *l, int *rge)
{
	int k;

	k = -1;
	ft_printf("[");
	while (++k < l->room_nb)
		ft_printf("%d,",rge[k]);
	ft_printf("]\n");
}
*/
static int		count_vertex(t_lemin *l, int *range)
{
	int k;

	k = -1;
	while (++k < l->room_nb)
		if (range[k] == 0)
			return (k);
	return (k);
}

static void		save_path(t_lemin *l)
{
	t_path	*elem;
	t_path	*tmp;
	t_path	*prev;

	elem = (t_path*)malloc(sizeof(t_path));
	elem->order = ft_rangedup(l->tab, l->room_nb);
	elem->nb = count_vertex(l, elem->order);
	elem->next = NULL;
	tmp = l->paths;
	if (tmp)
	{
		prev = tmp;
		while (tmp && elem->nb >= tmp->nb)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev == tmp)
			l->paths = elem;
		else
			prev->next = elem;
		elem->next = tmp;
	}
	else
		l->paths = elem;
}

int		find_path(t_lemin *l, int i)
{
	int j;

	j = -1;
	if (i == l->end - 1)
		return (1);
	while (++j < l->room_nb)
	{
		if (l->matrix[i][j] == '1' && isintab(l, j + 1))
		{
			l->tab[l->y++] = j + 1;
			if (!find_path(l, j))
				l->tab[l->y--] = 0;
			else
			{
				save_path(l);
				if (l->y-- != 1)
					l->tab[l->y] = 0;
				return (0);
			}
		}
	}
	return (0);
}
