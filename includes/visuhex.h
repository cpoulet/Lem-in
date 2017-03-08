/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuhex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:05:35 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/08 17:45:53 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUHEX_H
# define VISUHEX_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ERROR	ERROR1 ERROR2 ERROR3
# define ERROR1	"\t╔═╗ ╦═╗ ╦═╗ ╔═╗ ╦═╗\n"
# define ERROR2	"\t║╣  ╠╦╝ ╠╦╝ ║ ║ ╠╦╝\n"
# define ERROR3	"\t╚═╝ ╩╚═ ╩╚═ ╚═╝ ╩╚═\n"
# define LINE4(x)	ft_printf("|   \x1B[3%dm\\O/\x1B[0m   |", x)
# define LINE5(x)	ft_printf("|  \x1B[3%dm'-o-'\x1B[0m  |", x)
# define LINE6(x)	ft_printf("|   \x1B[3%dm/O\\\x1B[0m   |", x)
# define LINE7(x)	ft_printf("|    \x1B[3%dm^\x1B[0m    |", x)
# define BLANK		ft_printf("               ")
# define MID		ft_printf("             ")
# define NL			ft_printf("\n")
# define ANT		"0123456"

typedef struct	s_print
{
	int		mid;
	char	top;
	char	bot;
	char	*name;
	int		ant;
}				t_print;

typedef struct	s_box
{
	int				path;
	int				ant;
	char			*name;
	struct s_box	*next;
}				t_box;

typedef struct	s_hex
{
	int		ant_nb;
	int		path_nb;
	int		flag_s;
	int		first;
	int		width;
	char	first_line;
	char	*start;
	char	*end;
	t_box	*box;
}				t_hex;

void	print_box(t_print *p, int nb);

#endif
