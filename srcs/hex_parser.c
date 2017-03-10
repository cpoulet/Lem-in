/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:51:51 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 14:53:43 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

t_box	*loop(t_box *b, t_hex *h, int k)
{
	t_print *p;
	int		i;

	i = 0;
	p = NULL;
	while (++i <= h->path_nb)
	{
		if (!b)
			p = empty_box(p, 0);
		else if (!ft_strcmp(b->name, h->end))
		{
			p = empty_box(p, b);
			b = b->next;
		}
		else if (b->path == i)
		{
			p = init_box(p, b);
			b = b->next;
		}
		else
			p = empty_box(p, b);
	}
	print_box(p, h->path_nb, k);
	free_box(p);
	return (b);
}

void	print_graph(t_hex *h)
{
	t_box	*b;
	int		k;

	k = -1;
	while (++k < 8)
	{
		b = h->box;
		usleep(100000);
		ft_printf(INIT);
		print_start(h, k);
		print_branch(h);
		while (b)
			b = loop(b, h, k);
		if (h->ant_out)
		{
			print_branch(h);
			print_end(h, k);
		}
	}
}

void	reinit_graph(t_hex *h)
{
	t_box	*b;

	b = h->box;
	while (b)
	{
		b->ant = 0;
		b = b->next;
	}
}

void	parse_graph(t_hex *h, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!h->first_line && str[i] == 'L')
			add_path(h, &str[i + 1]);
		else if (str[i] == 'L')
			add_box(h, &str[i + 1]);
	}
	h->first_line = 1;
	print_graph(h);
	reinit_graph(h);
}

void	get_start(t_hex *h, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (h->flag_s)
	{
		h->start = ft_strnew(i);
		ft_strncpy(h->start, str, i);
	}
	else
	{
		h->end = ft_strnew(i);
		ft_strncpy(h->end, str, i);
	}
	h->flag_s = 0;
	h->flag_e = 0;
}
