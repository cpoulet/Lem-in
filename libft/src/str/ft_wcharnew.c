/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:09:05 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:07:16 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcharnew(size_t size)
{
	wchar_t *str;

	str = (wchar_t*)xmalloc(sizeof(*str) * (size + 1));
	while (size != 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}
