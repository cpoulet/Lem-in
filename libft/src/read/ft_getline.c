/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:35:32 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 17:47:59 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getline(const int fd, char **line)
{
	char	buff[2];
	char	*tmp;
	int		ret;

	*line = ft_strnew(0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		if (*buff == '\n')
			break ;
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		ft_strdel(&tmp);
	}
	return (ret);
}
