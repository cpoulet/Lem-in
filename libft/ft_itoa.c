/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:28:04 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 14:58:35 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = ft_nblen(n);
	if (n < 0)
	{
		nb = nb * -1;
		len++;
	}
	str = (char*)xmalloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len != 0)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
