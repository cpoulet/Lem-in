/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:55:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/10 15:51:54 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_link(t_lemin *l, int i)
{
	int nb;
	int ret;

	ret = 0;
	nb = l->room_nb;
	while (nb--)
		if (l->matrix[i][nb] == '1')
			ret++;
	return (ret);
}
/*
static int	*get_path(t_path *first, int i)
{
	t_path	*elem;

	elem = first;
	while (elem && --i)
		elem = elem->next;
	return (elem->order);
}

static int	get_nb(t_path *first, int i)
{
	t_path	*elem;

	elem = first;
	while (elem && --i)
		elem = elem->next;
	return (elem->nb);
}

static int	are_unique(t_lemin *l, int *p, int n)
{
	int		ret;
	int		*tmp;
	int		max;
	int		i;

	if (n == 0)
		return (0);
	tmp = ft_rangenew(l->room_nb);
	while (n--)
	{
		ret = 0;
		max = get_nb(l->paths, p[n]) - 1;
		while (++ret < max)
		{
			i = get_path(l->paths, p[n])[ret];
			tmp[i]++;
			if (tmp[i] >= 2)
				return (0);
		}
	}
	return (1);
}

static void print_p(int **p, int height, int width)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		ft_printf("[");
		while (++j < width - 1)
			ft_printf("%d, ", p[i][j]);
		while (++j < width)
			ft_printf("%d", p[i][j]);
		ft_printf("]\n");
	}
}
*/
static int	flux_max(t_lemin *l)
{
	int p1;
	int p2;
//	int	nb;
//	int	**p;

	if (l->paths->nb == 2)
		return (0);
	p1 = 1;
	p2 = 2;
	l->flux_out = count_link(l, l->start - 1);
	l->flux_in = count_link(l, l->end - 1);
	l->flux_max = ft_min(3, l->flux_max, l->flux_out, l->flux_in);
//	while (nb <= l->room_nb - 2)
//	{
//		nb = get_nb(l->paths, p1) + get_nb(l->paths, p2) - 4;
//	}
	ft_printf("out : %d\tin : %d\n", l->flux_out, l->flux_in);
	ft_printf("max : %d\n", l->flux_max);
	ft_printf(">%d\n", comb_u(3, 5));
//	print_p(p, 6, 2);
	return (1);
}

void		send_ants(t_lemin *l)
{
	if (!flux_max(l))
		l->flux_max = 0;
}
