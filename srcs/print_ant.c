/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:51:34 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 14:53:05 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuhex.h"

void	print_ant5(t_print *p, int k)
{
	if (k == 0)
		LINE11(p->color);
	else if (k == 1 || k == 7)
		LINE21(p->color);
	else if (k == 2 || k == 6)
		LINE31(p->color);
	else if (k == 3 || k == 5)
		LINE41(p->color);
	else
		LINE51(p->color);
}

void	print_ant6(t_print *p, int k)
{
	if (k == 0)
		LINE12(p->color);
	else if (k == 1 || k == 7)
		LINE22(p->color);
	else if (k == 2 || k == 6)
		LINE32(p->color);
	else if (k == 3 || k == 5)
		LINE42(p->color);
	else
		LINE52(p->color);
}

void	print_ant7(t_print *p, int k)
{
	if (k == 0)
		LINE13(p->color);
	else if (k == 1 || k == 7)
		LINE23(p->color);
	else if (k == 2 || k == 6)
		LINE33(p->color);
	else if (k == 3 || k == 5)
		LINE43(p->color);
	else
		LINE53(p->color);
}
