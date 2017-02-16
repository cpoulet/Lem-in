/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 10:43:59 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/10 15:42:15 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rec(int p, int n, int *svg, int k, int ret)
{
	int i;

	i = k + ret;
	if (!p)
	{
		i = 0;
		while (i < k)
			ft_printf("%d", svg[i++]);
		ft_printf("\n");
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

static int	fact(int nb)
{
	int	i;
	int	rslt;

	rslt = 1;
	if (nb >= 0)
	{
		i = nb;
		while (i-- > 1)
			rslt = rslt * i;
		return (rslt);
	}
	return (0);
}

static int	count(int p, int n)
{
	 int nb;

	 nb = n - p;
	 ft_printf("p > %d\t n > %d\t nb > %d\n", fact(p), fact(n), fact(nb));
	 return (fact(n) / (fact(p) * fact(nb)));
}

int			comb_u(int p, int n)
{
	int	svg[n];
	int i;

	i = -1;
	while (++i < n)
		svg[i] = 0;
	rec(p, n, svg, 0, 0);
	return (count(p, n));
}
