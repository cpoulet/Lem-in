/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:42:15 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:05:40 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t height, size_t width)
{
	char **tab;

	if (!height || !width)
		return (NULL);
	tab = (char**)xmalloc(sizeof(char*) * (height));
	while (height-- != 0)
		tab[height] = ft_strnew(width);
	return (tab);
}
