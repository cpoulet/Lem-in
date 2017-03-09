/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:46:06 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/09 18:48:01 by cpoulet          ###   ########.fr       */
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

void	print_line4(t_print *p, int nb)
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
			LINE4(p->color);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}
