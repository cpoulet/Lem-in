/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:27:16 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/10 11:46:59 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	intab(int *tab, int nb, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == nb)
			return (1);
	return (0);
}

static int	rec(int p, int n, int *tab, int *svg, int k)
{
	int i;

	i = 0;
	if (!p)
	{
		while (i < k)
			printf("%d", svg[i++]);
		printf("\n");
		return (0);
	}
	while (++i <= n)
	{
		if (intab(tab, i, n))
		{
			svg[k] = i;
			tab[i - 1] = 0;
			rec(p - 1, n, tab, svg, k + 1);
			tab[i - 1] = i;
		}
	}
	return (0);
}

int		comb(int p, int n)
{
	int	tab[n];
	int	svg[n];
	int i;

	i = -1;
	while (++i < n)
	{
		tab[i] = i + 1;
		svg[i] = 0;
	}
	rec(p, n, tab, svg, 0);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	comb(atoi(av[1]), atoi(av[2]));
	return (0);
}
