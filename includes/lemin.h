/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:50:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/03 17:34:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ANT1(x) "\x1B[3"x"m \\ |/ \n>C@oO\n  /| \\ \n\x1B[0m"
# define ANT2(x) "\x1B[3"x"m  \\| / \n>C@oO\n / |\\ \n\x1B[0m"

typedef struct	s_lemin
{
	int			read;
	int			start;
	int			end;
	int			room_nb;
	int			flag;
	char		**matrix;
	t_list		*first;
}				t_lemin;

void			parse_lemin(t_lemin *l);

#endif
