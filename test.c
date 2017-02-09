/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:27:16 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/09 18:11:23 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define NUM	"0123456789"
static int	intab(int *tab, int nb, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == nb)
			return (1);
	return (0);
}

static void	print_tab(int *tab, int size)
{
	int i;

	i = -1;
	write(1, "[", 1);
	while (++i < size)
	{
		write(1, &NUM[tab[i]], 1);
		write(1, " ", 1);
	}
	write(1, "]\n", 2);
}

static int	rec(int p, int n, int *tab, int *svg, int k)
{
	int i;

	i = 0;
//	print_tab(tab, n);
	if (!p)
	{
		printf("%d%d\n", svg[0], svg[1]);
		return (0);
	}
	while (++i <= n)
	{
		if (intab(tab, i, n))
		{
//			write(1, &NUM[i], 1);
//			write(1, "\n", 1);
			svg[k] = i;
			tab[i - 1] = 0;
			rec(p - 1, n, tab, svg, k + 1);
		}
		tab[i - 1] = i;
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

int	main()
{
	comb(2, 3);
	return (0);
}
