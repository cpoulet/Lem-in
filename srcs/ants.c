/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:48:00 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/09 18:50:19 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	print_link(int nb)
{
	BLANK;
	while (nb--)
	{
		LINK;
		if (nb)
			BLANK;
	}
	NL;
}

void	print_e(t_print *p, char *str)
{
	int		i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	ft_printf("%s", str);
	NL;
}

void	print_branch(t_hex *h)
{
	int nb;

	nb = h->path_nb;
	if (nb == 1)
		return ;
	BLANK;
	ft_printf("     +-----");
	while (--nb)
	{
		ft_printf("---------------");
		if (nb - 1)
			ft_printf("-----------");
	}
	ft_printf("-----+     ");
	NL;
}

void	print_box(t_print *p, int nb)
{
	t_print *svg;

	if (p->type == 0)
		print_link(nb);
	else if (p->type == 1)
		print_e(p, RED "   START" EOC);
	else if (p->type == 2)
		print_e(p, "     |");
	svg = p;
	print_line1(svg, nb);
	print_line2(svg, nb);
	print_line3(svg, nb);
	print_line4(svg, nb);
	print_line5(svg, nb);
	print_line6(svg, nb);
	print_line7(svg, nb);
	print_line8(svg, nb);
	if (p->type == 0)
		print_link(nb);
	else if (p->type == 1)
		print_e(p, "     |");
	else if (p->type == 2)
		print_e(p, RED "   END" EOC);
}
