/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:24 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/06 16:19:14 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
/*
static void	print_lst(t_lemin *l)
{
	t_list	*elem;

	if (l->first)
	{
		elem = l->first;
		while (elem)
		{
			write(1, elem->content, elem->content_size);
			write(1, "\n", 1);
			elem = elem->next;
		}
	}
}
*/

void	print_paths(t_lemin *l)
{
	t_path	*elem;
	int		k;

	elem = l->paths;
	while (elem)
	{
		k = -1;
		ft_printf("nb = %d\t[", elem->nb);
		while (++k < l->room_nb)	
			ft_printf("%d,", elem->list[k]);
		ft_printf("]\n");
		elem = elem->next;
	}
}

static void	print_matrix(t_lemin *l)
{
	int		i;
	int		j;
	int		k;
	t_list	*elem;

	i = -1;
	ft_printf("\n");
	while (++i < l->room_nb)
	{
		j = -1;
		k = 0;
		elem = l->first;
		while (k++ < i)
			elem = elem->next;
		write(1, elem->content, elem->content_size);
		write(1, "\t", 1);
		while (++j < l->room_nb)
		{
			if (l->matrix[i][j] == '1')
				ft_printf(GRN"1 "EOC);
			else
				ft_printf("0 ");
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

static void	init_lemin(t_lemin *l)
{
	l->first = 0;
	l->paths = 0;
	l->read = 1;
	l->start = 0;
	l->end = 0;
	l->flag = 0;
	l->room_nb = 0;
	l->y = 0;
}

void		error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

int			main()
{
	t_lemin	l;
	
	init_lemin(&l);
	parse_lemin(&l);
	if (l.start == 0 || l.end == 0)
		error("ERROR");
	print_matrix(&l);
//	print_lst(&l);
	ft_printf("nb = %d\n", l.room_nb);
	ft_printf("start = %d\tend = %d\n", l.start, l.end);
	l.path[l.y++] = l.start;
	find_path(&l, l.start - 1);
	print_paths(&l);
	return (0);
}
