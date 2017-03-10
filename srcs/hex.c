/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:16:39 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 13:46:08 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	init_hex(t_hex *h)
{
	h->path_nb = 0;
	h->first_line = 0;
	h->first = 0;
	h->flag_s = 0;
	h->flag_e = 0;
	h->end = 0;
	h->box = 0;
	h->ant_out = 0;
	h->ant_max = 0;
}

void	error(void)
{
	ft_printf(RED);
	ft_printf(ERROR);
	ft_printf(EOC);
	exit(1);
}

int		main(void)
{
	char	*line;
	t_hex	hex;

	init_hex(&hex);
	while (ft_getline(0, &line))
	{
		if (!hex.first++)
		{
			hex.first = 1;
			hex.ant_nb = atoi(line);
		}
		else if (!ft_strncmp(line, "##start", 7))
			hex.flag_s = 1;
		else if (!ft_strncmp(line, "##end", 5))
			hex.flag_e = 1;
		else if (!ft_strncmp(line, "ERROR", 5))
			error();
		else if (hex.flag_s == 1 || hex.flag_e == 1)
			get_start(&hex, line);
		else if (line[0] == 'L')
			parse_graph(&hex, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
