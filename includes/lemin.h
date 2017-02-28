/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:50:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/28 15:34:33 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "queue.h"

# define ANT1(x) "\x1B[3"x"m \\ |/ \n>C@oO\n  /| \\ \n\x1B[0m"
# define ANT2(x) "\x1B[3"x"m  \\| / \n>C@oO\n / |\\ \n\x1B[0m"

typedef struct	s_room
{
	int				id;
	struct s_room	*next;
}				t_room;

typedef struct	s_path
{
	int				nb;
	t_room			*first;
	struct s_path	*next;
}				t_path;

typedef struct	s_flux
{
	int				flux;
	t_room			*path;
	struct s_flux	*next;
}				t_flux;

typedef struct	s_ek
{
	char		**flow;
	int			flux;
	t_queue		*queue;
	int			*par;
	t_flux		*first;
}				t_ek;

typedef struct	s_lemin
{
	int			read;
	int			start;
	int			end;
	int			room_nb;
	int			flag;
	char		**matrix;
	char		**svg;
	int			*tab;
	int			ants;
	int			flux_out;
	int			flux_in;
	int			flux_max;
	int			y;
	t_list		*rooms;
	t_path		*paths;
}				t_lemin;

void			error(char *str);
void			parse_lemin(t_lemin *l);
void			print_paths(t_lemin *l);
char			*print_room(t_lemin *l, int i);
void			send_ants(t_lemin *l);
void			edmondskarp(t_lemin *l);

#endif
