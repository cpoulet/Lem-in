/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:43:21 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:04:13 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	int		i;
	int		nb;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	nb = ft_nbword(s, c);
	str = (char**)xmalloc(sizeof(*str) * (nb + 1));
	while (*s == c)
		s++;
	str[i] = 0;
	if (*s == '\0')
		return (str);
	while (i < nb && *s)
	{
		str[i++] = ft_first_word(s, c);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	str[nb] = 0;
	return (str);
}
