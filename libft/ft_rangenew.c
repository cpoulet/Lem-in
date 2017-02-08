/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:21:03 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:03:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rangenew(size_t size)
{
	int *range;

	range = (int*)xmalloc(sizeof(int) * (size));
	while (size != 0)
		range[--size] = 0;
	return (range);
}
