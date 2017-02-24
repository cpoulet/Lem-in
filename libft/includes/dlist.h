/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:34:29 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 14:17:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include "libft.h"

typedef struct			s_dlistelem
{
	void				*data;
	struct s_dlistelem	*prev;
	struct s_dlistelem	*next;
}						t_dlistelem;

typedef struct			s_dlist
{
	int					size;
	int					(*match)(const void *key1, const void *key2);
	void				(*destroy)(void *data);
	t_dlistelem			*head;
	t_dlistelem			*tail;
}						t_dlist;

void					dlist_init(t_dlist *list, void (*destroy)(void *data));
void					dlist_destroy(t_dlist *list);
int						dlist_ins_next(t_dlist *list, t_dlistelem *elem,
														const void *data);
int						dlist_ins_prev(t_dlist *list, t_dlistelem *elem,
														const void *data);
int						dlist_remove(t_dlist *list, t_dlistelem *elem,
															void **data);

#endif
