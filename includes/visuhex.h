/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuhex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:05:35 by cpoulet           #+#    #+#             */
/*   Updated: 2017/03/10 14:56:14 by cpoulet          ###   ########.fr       */
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
# define A10 " ⎝  ̢O ̡⎠  "
# define A11 " ⎝  ̡O ̢   "
# define A12 "   ༼ჲ༽⎞  "
# define A13 "   ֯   ֯   "
# define A20 " ⎝  ̢O ̡⟋  "
# define A21 " ⟍ ͟ ̡O ̢ ͟  "
# define A22 "   ༼ჲ༽   "
# define A23 "   ֯   ֯   "
# define A30 "  ⟍ ̢O ͟ ͟  "
# define A31 "  ͜ ͜ ̡O ̢ ͟ ̡ "
# define A32 "   ༼ჲ༽   "
# define A33 "   ֯   ֯   "
# define A40 "   ͟ ͟O ̡⟋  "
# define A41 "   ͟ ̡O ̢ ͜৴ "
# define A42 "   ༼ჲ༽   "
# define A43 "   ֯   ֯   "
# define A50 "  ⟍ ̢O ̡⎠  "
# define A51 "    ̡O ̢⎠  "
# define A52 "  ⎠༼ჲ༽   "
# define A53 "   ֯   ֯   "
# define LINE10(x)	ft_printf("|\x1B[3%dm" A10 "\x1B[0m|", x)
# define LINE11(x)	ft_printf("|\x1B[3%dm" A11 "\x1B[0m|", x)
# define LINE12(x)	ft_printf("|\x1B[3%dm"  A12 "\x1B[0m|", x)
# define LINE13(x)	ft_printf("|\x1B[3%dm" A13 "\x1B[0m|", x)
# define LINE20(x)	ft_printf("|\x1B[3%dm" A20 "\x1B[0m|", x)
# define LINE21(x)	ft_printf("|\x1B[3%dm" A21 "\x1B[0m|", x)
# define LINE22(x)	ft_printf("|\x1B[3%dm"  A22 "\x1B[0m|", x)
# define LINE23(x)	ft_printf("|\x1B[3%dm" A23 "\x1B[0m|", x)
# define LINE30(x)	ft_printf("|\x1B[3%dm" A30 "\x1B[0m|", x)
# define LINE31(x)	ft_printf("|\x1B[3%dm" A31 "\x1B[0m|", x)
# define LINE32(x)	ft_printf("|\x1B[3%dm"  A32 "\x1B[0m|", x)
# define LINE33(x)	ft_printf("|\x1B[3%dm" A33 "\x1B[0m|", x)
# define LINE40(x)	ft_printf("|\x1B[3%dm" A40 "\x1B[0m|", x)
# define LINE41(x)	ft_printf("|\x1B[3%dm" A41 "\x1B[0m|", x)
# define LINE42(x)	ft_printf("|\x1B[3%dm"  A42 "\x1B[0m|", x)
# define LINE43(x)	ft_printf("|\x1B[3%dm" A43 "\x1B[0m|", x)
# define LINE50(x)	ft_printf("|\x1B[3%dm" A50 "\x1B[0m|", x)
# define LINE51(x)	ft_printf("|\x1B[3%dm" A51 "\x1B[0m|", x)
# define LINE52(x)	ft_printf("|\x1B[3%dm"  A52 "\x1B[0m|", x)
# define LINE53(x)	ft_printf("|\x1B[3%dm" A53 "\x1B[0m|", x)
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

void			print_box(t_print *p, int nb, int k);
void			print_start(t_hex *h, int k);
void			print_branch(t_hex *h);
void			print_end(t_hex *h, int k);
void			print_line1(t_print *p, int nb);
void			print_line2(t_print *p, int nb);
void			print_line3(t_print *p, int nb);
void			print_line4(t_print *p, int nb, int k);
void			print_line5(t_print *p, int nb, int k);
void			print_line6(t_print *p, int nb, int k);
void			print_line7(t_print *p, int nb, int k);
void			print_line8(t_print *p, int nb);
void			get_start(t_hex *h, char *str);
void			parse_graph(t_hex *h, char *str);
void			free_box(t_print *p);
void			add_path(t_hex *h, char *str);
void			add_box(t_hex *h, char *str);
void			print_ant4(t_print *p, int k);
void			print_ant5(t_print *p, int k);
void			print_ant6(t_print *p, int k);
void			print_ant7(t_print *p, int k);
int				isbox(t_hex *h, char *str, int ant);
t_print			*init_box(t_print *p, t_box *b);
t_print			*empty_box(t_print *p, t_box *b);

#endif
