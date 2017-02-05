/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:46:54 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/05 20:19:01 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		isintab(t_lemin *l, int i)
{
	int k;

	k = -1;
	while (++k < l->room_nb)
		if (i == l->path[l->x][k])
			return (0);
	return (1);
}

void	print_path(t_lemin *l)
{
	int k;

	k = -1;
	ft_printf("[");
	while (++k < l->room_nb)
		ft_printf("%c,",l->path[l->x][k]);
	ft_printf("]\n");
}

int		find_path(t_lemin *l, int i, int j)
{
	print_path(l);
	if (i == l->end - 1)
		return (1);
	if (j >= l->room_nb)
		return (0);
	if (l->matrix[i][j] == '1' && isintab(l, j + 49))
	{
		ft_printf(">>%c", i + 49);
		l->path[l->x][l->y++] = i + 49;
		if (!find_path(l, j, 0))
			find_path(l, i, j + 1);
	}
	else
		find_path(l, i, j + 1);
	return (0);
}
