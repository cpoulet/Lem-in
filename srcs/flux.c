/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:55:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 18:18:33 by cpoulet          ###   ########.fr       */
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

void		flux_max(t_lemin *l)
{
	l->flux_out = count_link(l, l->start - 1);
	l->flux_in = count_link(l, l->end - 1);
	ft_printf("out : %d\tin : %d\n", l->flux_out, l->flux_in);
	l->flux_max = ft_min(3, l->flux_max, l->flux_out, l->flux_in);
	ft_dprintf(1, "max : %d\n", l->flux_max);
}

void	send_ants(t_lemin *l)
{
	flux_max(l);
}
