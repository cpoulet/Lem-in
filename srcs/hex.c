/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:16:39 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/08 17:47:27 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

char	*get_name(char *str)
{
	int 	i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	ret = ft_strsub(str, 0, i);
	return (ret);
}

void	add_path(t_hex *h, char *str)
{
	t_box	*b;
	t_box	*new;

	h->path_nb++;
	new = xmalloc(sizeof(t_box));
	new->ant = str[0] - '0';
	new->path = new->ant;
	new->name = get_name(str + 2);
	new->next = NULL;
	b = h->box;
	if (!b)
		h->box = new;
	else
	{
		while (b->next)
			b = b->next;
		b->next = new;
	}
}

int		isbox(t_hex *h, char *str, int ant)
{
	t_box	*b;
	t_box	*new;
	t_box	*svg;

	b = h->box;
	while (b)
	{
		if (!ft_strncmp(str, b->name, ft_strlen(b->name)))
		{
			b->ant = ant;
			return (1);
		}
		svg = b;
		b = b->next;
	}
	new = xmalloc(sizeof(t_box));
	svg->next = new;
	new->ant = ant;
	new->path = new->ant;
	new->name = get_name(str);
	new->next = NULL;
	return (0);
}

void	add_box(t_hex *h, char *str)
{
	int 	ant;

	ant = ft_atoi_skip(&str);
	str++;
	isbox(h, str, ant);
}

void	print_start(t_hex *h)
{
	t_print p;

	p.mid = (h->path_nb - 1) < 0 ? 0 : h->path_nb - 1;
	p.top = '-';
	p.bot = '+';
	p.name = h->start;
	p.ant = h->ant_nb ? (h->ant_nb % 6 + 1) : 0;
	print_box(&p, 1);
}

void	print_graph(t_hex *h)
{
	t_box	*b;

	b = h->box;
	print_start(h);
	ft_printf("__________________________\n");
	ft_printf("nb = %d\n", h->path_nb);
	while (b)
	{
		ft_printf("path = %d\t", b->path);
		ft_printf("name = %s\t", b->name);
		ft_printf("ant = %d\n", b->ant);
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
}

void	get_start(t_hex *h, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	h->start = ft_strnew(i);
	ft_strncpy(h->start, str, i);
	printf("start = %s\n", h->start);
	h->flag_s = 0;
}

void	init_hex(t_hex *h)
{
	h->path_nb = 0;
	h->first_line = 0;
	h->first = 0;
	h->flag_s = 0;
	h->end = 0;
	h->box = 0;
	h->width = 0;
}

void	error()
{
	ft_printf(RED ERROR EOC);
	exit(1);
}

int		main(void)
{
	char	*line;
	t_hex	hex;

	init_hex(&hex);
	while (ft_getline(0, &line))
	{
		if (!hex.first)
		{
			hex.first = 1;
			hex.ant_nb = atoi(line);
		}
		else if (!ft_strncmp(line, "##start", 7))
			hex.flag_s = 1;
		else if (!ft_strncmp(line, "ERROR", 5))
			error();
		else if (hex.flag_s == 1)
			get_start(&hex, line);
		else if (line[0] == 'L')
			parse_graph(&hex, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
//	print_box(&hex, 2);
}
