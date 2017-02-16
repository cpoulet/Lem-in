/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:40:29 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 14:49:49 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*xmalloc(size_t n)
{
	void	*p;

	p = malloc(n);
	if (p == NULL)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	return (p);
}
