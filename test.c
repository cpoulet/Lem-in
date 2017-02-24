/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:08:48 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 16:22:24 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

void	list_print(t_list *list)
{
	t_listelem	*elem;
	int		*nb;

	elem = list->head;
	while (elem)
	{
		nb = (elem->data);
		printf("%d\n", *nb);
		elem = elem->next;
	}
}

int	main()
{
	t_list	lst;
	int		nb;
	int		*a;
	int		*b;
	int		size;
	int		*val;
	t_listelem	*c;
	t_listelem	*d;

	list_init(&lst, free);
	nb = 0;
	printf("size = %d\n", lst.size);
	while (nb++ < 10)
	{
		val = malloc(sizeof(int));
		*val = nb;
		list_ins_next(&lst, NULL, val);
		a = lst.head->data;
		b = lst.tail->data;
		size = lst.size;
		printf("h =%d\tt =%d\tsize = %d\n", *a, *b, size);
	}
	list_print(&lst);
	return (0);
}

