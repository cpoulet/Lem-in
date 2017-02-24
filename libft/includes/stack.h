/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:20:53 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/24 14:22:58 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "list.h"
# define STACK_INIT		list_init
# define STACK_DESTROY	list_destroy

typedef	t_list	t_stack;

int		stack_push(t_stack *stack, const void *data);
int		stack_pop(t_stack *stack, void **data);

#endif
