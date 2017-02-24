/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 11:54:04 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 14:18:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"

typedef struct			s_listelem
{
	void				*data;
	struct s_listelem	*next;
}						t_listelem;

typedef struct			s_list
{
	int					size;
	int					(*match)(const void *key1, const void *key2);
	void				(*destroy)(void *data);
	t_listelem			*head;
	t_listelem			*tail;
}						t_list;

void					list_init(t_list *list, void (*destroy)(void *data));
void					list_destroy(t_list *list);
int						list_ins_next(t_list *list, t_listelem *elem,
															const void *data);
int						list_rem_next(t_list *list, t_listelem *elem,
																void **data);

#endif
