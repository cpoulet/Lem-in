/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:43:59 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/10 15:07:27 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int    rec(int p, int n, int *svg, int k, int ret)
{
	int i;

	i = k + ret;
	if (!p)
	{
		i = 0;
		while (i < k)
			printf("%d", svg[i++]);
		printf("\n");
		return (1);
	}
	while (++i <= n)
	{
		svg[k] = i;
		rec(p - 1, n, svg, k + 1, ret);
		ret++;
	}
	return (0);
}

int        comb(int p, int n)
{
	int    svg[n];
	int i;

	i = -1;
	while (++i < n)
		svg[i] = 0;
	rec(p, n, svg, 0, 0);
	return (0);
}
