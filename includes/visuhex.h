/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuhex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:05:35 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/07 18:30:27 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUHEX_H
# define VISUHEX_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ANT1(x) "\x1B[3"x"m \\ |/ \n>C@oO\n  /| \\ \n\x1B[0m"
# define ANT2(x) "\x1B[3"x"m  \\| / \n>C@oO\n / |\\ \n\x1B[0m"

typedef struct	s_vroom
{
	int				ant;
	char			*name;
	struct s_vroom	*next;
}				t_vroom;

typedef struct	s_vpath
{
	int				id;
	t_vroom			*rooms;
	struct s_vpath	*next;
}				t_vpath;

typedef struct	s_hex
{
	int		path_nb;
	char	first_line;
	char	*start;
	char	*end;
	t_vpath	*paths;
}				t_hex;

#endif
