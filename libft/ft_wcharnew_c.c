/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharnew_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:11:55 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:06:26 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcharnew_c(size_t size, char c)
{
	wchar_t *str;

	str = (wchar_t*)xmalloc(sizeof(*str) * (size + 1));
	str[size] = '\0';
	while (size != 0)
		str[--size] = c;
	return (str);
}
