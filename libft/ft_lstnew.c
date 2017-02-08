/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 10:11:03 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/08 15:00:44 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list*)xmalloc(sizeof(t_list));
	if (!content || !content_size)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = ft_memalloc(content_size);
		elem->content_size = content_size;
		ft_memcpy(elem->content, content, content_size);
	}
	elem->next = NULL;
	return (elem);
}
