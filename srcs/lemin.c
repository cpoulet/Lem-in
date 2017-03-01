/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:49:24 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/01 13:07:00 by cpoulet          ###   ########.fr       */
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
/*
void		print_paths(t_lemin *l)
{
	t_path	*elem;
	int		k;

	elem = l->paths;
	while (elem)
	{
		k = -1;
		ft_printf("nb = %d\t[", elem->nb);
		while (++k < l->room_nb)
			ft_printf("%s,", print_room(l, elem->order[k]));
		ft_printf("]\n");
		elem = elem->next;
	}
}
*/
static void	print_matrix(t_lemin *l)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("\n");
	while (++i < l->room_nb)
	{
		j = -1;
		ft_printf("%s\t", print_room(l, i + 1));
		while (++j < l->room_nb)
		{
			if (l->matrix[i][j] == 1)
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
	l->rooms = xmalloc(sizeof(t_list));
	l->paths = 0;
	l->read = 1;
	l->start = 0;
	l->end = 0;
	l->flag = 0;
	l->room_nb = 0;
	l->ants = 0;
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
	ft_printf("nb_room = %d\n", l.room_nb);
	ft_printf("start = %d", l.start);
	ft_printf("\tend = %d\n", l.end);
	ft_printf("start = %s", print_room(&l, l.start));
	ft_printf("\tend = %s\n", print_room(&l, l.end));
	print_matrix(&l);
	edmondskarp(&l);
	return (0);
}
