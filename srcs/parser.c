/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:29:43 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/03 18:18:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	find_lst(t_lemin *l, char *str, int i)
{
	t_list	*elem;
	int		k;

	k = 1;
	elem = l->first;
	while (elem && ft_memcmp(str, elem->content, i))
	{
		elem = elem->next;
		k++;
	}
	if (!elem)
		k = 0;
	return (k);
}

static void	fill_matrix(t_lemin *l, char *str, int n)
{
	int i;
	int j;

	if (!l->flag)
	{
		l->flag = 1;
		l->matrix = ft_tabnew(l->room_nb, l->room_nb);
	}
	if (!(i = find_lst(l, str, n)))
		l->read = 0;
	else
	{
		str += n + 1;
		n = 0;
		while (str[n])
			n++;
		if (!(j = find_lst(l, str, n)))
			l->read = 0;
		else
			l->matrix[i - 1][j - 1] = '1';
	}
}

static void	parse_room(t_lemin *l, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '-')
		i++;
	if (!str[i])
		l->read = 0;
	else if (str[i] == ' ')
	{
		if (!l->first)
			l->first = ft_lstnew(str, i++);
		else
			ft_lstaddend(&(l->first), ft_lstnew(str, i++));
		str += i;
		if (!ft_atoi_skip(&str) || !ft_atoi_skip(&str) || *str)
			l->read = 0;
		l->room_nb++;
	}
	else
		fill_matrix(l, str, i);
}

void		parse_lemin(t_lemin *l)
{
	char	*line;

	l->read = 1;
	while (ft_getline(0, &line) && l->read)
	{
		if (*line == '#')
		{
			if (!ft_memcmp(line, "##start\0", 8))
				l->start = l->room_nb + 1;
			else if (!ft_memcmp(line, "##end\0", 6))
				l->end = l->room_nb + 1;
		}
		else if (ft_isprint(*line) && *line != 32 &&
				*line != 'L' && *line != '*')
			parse_room(l, line);
		else
			l->read = 0;
		ft_strdel(&line);
	}
}
