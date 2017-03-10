/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:48:30 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 13:59:14 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	print_line5(t_print *p, int nb, int k)
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
			print_ant5(p, k);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_line6(t_print *p, int nb, int k)
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
			print_ant6(p, k);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_line7(t_print *p, int nb, int k)
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
			print_ant7(p, k);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}

void	print_line8(t_print *p, int nb)
{
	int i;
	int k;

	k = nb;
	i = p->mid;
	while (i--)
		MID;
	BLANK;
	while (nb-- && p)
	{
		if (p->empty)
			LINK;
		else
			ft_printf("'----%c----'", p->bot);
		if (nb)
			BLANK;
		p = p->next;
	}
	NL;
}
