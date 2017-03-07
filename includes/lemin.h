/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:50:19 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 17:06:49 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "queue.h"

typedef struct	s_room
{
	int				id;
	int				ant;
	struct s_room	*next;
}				t_room;

typedef struct	s_path
{
	int				len;
	t_room			*first;
	struct s_path	*next;
}				t_path;

typedef struct	s_flux
{
	int				flux;
	int				min;
	int				round;
	t_path			*path;
	struct s_flux	*next;
}				t_flux;

typedef struct	s_ek
{
	char		**flow;
	int			flux;
	int			depth;
	int			nb;
	int			end;
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
	int			ants;
	int			round;
	t_flux		*flux_to_print;
	t_list		*rooms;
	t_flux		*paths;
}				t_lemin;

void			error(char *str);
void			parse_lemin(t_lemin *l);
void			print_paths(t_lemin *l);
char			*print_room(t_lemin *l, int i);
void			send_ants(t_lemin *l);
void			ek_free(t_ek *e);
void			data_free(t_lemin *l);
void			edmondskarp(t_lemin *l);
void			save_flux(t_ek *ek, int start, t_path *p);
t_flux			*addflux(t_ek *e, int len);

#endif
