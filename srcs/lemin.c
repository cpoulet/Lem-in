/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:24 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/05 18:55:00 by cpoulet          ###   ########.fr       */
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
	l->read = 1;
	l->start = 0;
	l->end = 0;
	l->flag = 0;
	l->room_nb = 0;
	l->x = 0;
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
	find_path(&l, l.start - 1, 0);
	return (0);
}
