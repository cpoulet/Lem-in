/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:48:00 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/08 17:45:28 by cpoulet          ###   ########.fr       */
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
	while (nb--)
	{
		ft_printf(",----%c----,", p->top);
		if (nb)
			BLANK;
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
	while (nb--)
	{
		ft_printf("|  %5.5s  |", p->name);
		if (nb)
			BLANK;
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
	while (nb--)
	{
		ft_printf("|  %3d    |", p->ant);
		if (nb)
			BLANK;
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
	while (nb--)
	{
		LINE4(p->ant);
		if (nb)
			BLANK;
	}
	NL;
}

void	print_line5(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb--)
	{
		LINE5(p->ant);
		if (nb)
			BLANK;
	}
	NL;
}

void	print_line6(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb--)
	{
		LINE6(p->ant);
		if (nb)
			BLANK;
	}
	NL;
}

void	print_line7(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb--)
	{
		LINE7(p->ant);
		if (nb)
			BLANK;
	}
	NL;
}

void	print_line8(t_print *p, int nb)
{
	int i;

	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb--)
	{
		ft_printf("'----%c----'", p->bot);
		if (nb)
			BLANK;
	}
	NL;
}

void	print_box(t_print *p, int nb)
{
	print_line1(p, nb);
	print_line2(p, nb);
	print_line3(p, nb);
	print_line4(p, nb);
	print_line5(p, nb);
	print_line6(p, nb);
	print_line7(p, nb);
	print_line8(p, nb);
}
