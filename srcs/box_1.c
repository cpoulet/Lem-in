/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:46:06 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 14:53:20 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	print_line1(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb-- && p)
	{
		if (p->empty)
			LINK;
		else
			ft_printf(",----%c----,", p->top);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_line2(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb-- && p)
	{
		if (p->empty)
			LINK;
		else
			ft_printf("|  %5.5s  |", p->name);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_line3(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb-- && p)
	{
		if (p->empty)
			LINK;
		else if (p->ant)
			ft_printf("|\x1B[3%dm  %3d    " EOC "|", p->color, p->ant);
		else
			ft_printf("|         |");
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_ant4(t_print *p, int k)
{
	if (k == 0)
		LINE10(p->color);
	else if (k == 1 || k == 7)
		LINE20(p->color);
	else if (k == 2 || k == 6)
		LINE30(p->color);
	else if (k == 3 || k == 5)
		LINE40(p->color);
	else
		LINE50(p->color);
}

void	print_line4(t_print *p, int nb, int k)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb-- && p)
	{
		if (p->empty)
			LINK;
		else
			print_ant4(p, k);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}
