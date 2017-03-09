/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:28:46 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/09 19:35:33 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

char	*get_name(char *str)
{
	int		i;
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
	h->ant_max++;
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
	if (!ft_strncmp(h->end, str, ft_strlen(h->end)))
		return (h->ant_out++);
	while (b)
	{
		if (!ft_strncmp(str, b->name, ft_strlen(b->name)))
			return (b->ant = ant);
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
	int	ant;

	ant = ft_atoi_skip(&str);
	h->ant_max = ant > h->ant_max ? ant : h->ant_max;
	str++;
	isbox(h, str, ant);
}

void	free_box(t_print *p)
{
	t_print *next;

	while (p)
	{
		next = p->next;
		free(p->name);
		free(p);
		p = next;
	}
}
