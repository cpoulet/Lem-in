/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangedup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:21:03 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/06 12:39:41 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rangedup(int *range, size_t size)
{
	int *dup;

	if (!(dup = (int*)malloc(sizeof(int) * (size))))
		return (NULL);
	while (size-- != 0)
		dup[size] = range[size];
	return (dup);
}
