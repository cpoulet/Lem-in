/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuhex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:05:35 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/09 19:35:07 by cpoulet          ###   ########.fr       */
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
# define LINK		ft_printf("     |     ")
# define BLANK		ft_printf("               ")
# define MID		ft_printf("             ")
# define NL			ft_printf("\n")
# define FNL		ft_printf("\n\n")

typedef struct	s_print
{
	char			type;
	int				empty;
	int				mid;
	char			top;
	char			bot;
	char			*name;
	int				ant;
	int				color;
	struct s_print	*next;
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
	int		ant_max;
	int		ant_out;
	int		path_nb;
	char	flag_s;
	char	flag_e;
	int		first;
	char	first_line;
	char	*start;
	char	*end;
	t_box	*box;
}				t_hex;

void	print_box(t_print *p, int nb);
void	print_start(t_hex *h);
void	print_branch(t_hex *h);
void	print_end(t_hex *h);
void	print_line1(t_print *p, int nb);
void	print_line2(t_print *p, int nb);
void	print_line3(t_print *p, int nb);
void	print_line4(t_print *p, int nb);
void	print_line5(t_print *p, int nb);
void	print_line6(t_print *p, int nb);
void	print_line7(t_print *p, int nb);
void	print_line8(t_print *p, int nb);
void	get_start(t_hex *h, char *str);
void	parse_graph(t_hex *h, char *str);
void	free_box(t_print *p);
void	add_path(t_hex *h, char *str);
void	add_box(t_hex *h, char *str);
int		isbox(t_hex *h, char *str, int ant);
t_print	*init_box(t_print *p, t_box *b);
t_print	*empty_box(t_print *p, t_box *b);

#endif
