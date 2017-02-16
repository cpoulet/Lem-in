/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_i_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:42:15 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:05:05 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_tab_i_new(size_t height, size_t width)
{
	int **tab;

	if (!height || !width)
		return (NULL);
	tab = (int**)xmalloc(sizeof(int*) * (height));
	while (height-- != 0)
		tab[height] = ft_rangenew(width);
	return (tab);
}
