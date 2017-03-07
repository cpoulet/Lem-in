/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:16:39 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 18:45:42 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	add_path(t_hex *h, char *str)
{
	t_vpath	*p;
	t_vpath	*new;

	h->path_nb++;
	new = xmalloc(sizeof(t_vpath));
	new->rooms = xmalloc(sizeof(t_vroom));
	new->id = h->path_nb;
	new->next = NULL;
	p = h->paths;
	if (!p)
		h->paths = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	ft_printf("%s\n", str);
}

void	parse_graph(t_hex *h, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!h->first_line && str[i] == '-')
			add_path(h, &str[i - 1]);
	}
	h->first_line = 1;
}

void	init_hex(t_hex *h)
{
	h->path_nb = 0;
	h->first_line = 0;
	h->start = 0;
	h->end = 0;
	h->paths = 0;
}

int		main(void)
{
	char	*line;
	t_hex	hex;

	init_hex(&hex);
	while (ft_getline(0, &line))
	{
		if (line[0] == 'L')
			parse_graph(&hex, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
