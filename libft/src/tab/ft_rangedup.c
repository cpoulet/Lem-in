/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangedup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:21:03 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:02:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rangedup(int *range, size_t size)
{
	int *dup;

	dup = (int*)xmalloc(sizeof(int) * (size));
	while (size-- != 0)
		dup[size] = range[size];
	return (dup);
}
