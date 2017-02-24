# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 09:22:13 by cpoulet           #+#    #+#              #
#    Updated: 2017/02/24 16:41:43 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar.c\
		ft_strlcpy.c\
		ft_putchar_fd.c\
		ft_strlen.c\
		ft_wstrlen.c\
		ft_putendl.c\
		ft_strmap.c\
		ft_putendl_fd.c\
		ft_strmapi.c\
		ft_atoi.c\
		ft_approx.c\
		ft_atoi_skip.c\
		ft_putnbr.c\
		ft_strncat.c\
		ft_bzero.c\
		ft_putnbr_fd.c\
		ft_strncmp.c\
		ft_putstr.c\
		ft_strncpy.c\
		ft_first_word.c\
		ft_putstr_fd.c\
		ft_strnequ.c\
		ft_isalnum.c\
		ft_strcat.c\
		ft_strnew.c\
		ft_rangenew.c\
		ft_rangedup.c\
		ft_tabnew.c\
		ft_tab_i_new.c\
		ft_wcharnew.c\
		ft_wcharnew_c.c\
		ft_isalpha.c\
		ft_ishexa.c\
		ft_get_hexa.c\
		ft_get_nb_b.c\
		ft_memalloc.c\
		ft_strchr.c\
		ft_strnstr.c\
		ft_isascii.c\
		ft_memccpy.c\
		ft_strclr.c\
		ft_strrchr.c\
		ft_isdigit.c\
		ft_isblank.c\
		ft_memchr.c\
		ft_strcmp.c\
		ft_strsplit.c\
		ft_isprint.c\
		ft_memcmp.c\
		ft_strcpy.c\
		ft_strstr.c\
		ft_strredim.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_memcpy.c\
		ft_strdel.c\
		ft_strsub.c\
		ft_memdel.c\
		ft_strdup.c\
		ft_strtrim.c\
		ft_memmove.c\
		ft_strequ.c\
		ft_tolower.c\
		ft_strtolow.c\
		ft_strtoup.c\
		ft_memset.c\
		ft_striter.c\
		ft_toupper.c\
		ft_nblen.c\
		ft_u_nblen.c\
		ft_nblen_b.c\
		ft_striteri.c\
		ft_nbword.c\
		ft_strjoin.c\
		ft_power.c\
		ft_u_power.c\
		ft_strlcat.c\
		ft_tabdel.c\
		ft_is_char.c\
		ft_max.c\
		ft_min.c\
		get_next_line.c\
		ft_printf.c\
		buffer.c\
		format.c\
		fwp_bin.c\
		fwp_int.c\
		fwp_hex.c\
		fwp_ptr.c\
		fwp_wstr.c\
		fwp_u_int.c\
		fwp_char.c\
		fwp_oct.c\
		fwp_wchar.c\
		parser.c\
		cast_mod.c\
		lst_arg.c\
		str_field.c\
		num_field.c\
		ft_getline.c\
		xmalloc.c\
		list_init.c\
		list_destroy.c\
		list_ins_next.c\
		list_rem_next.c\
		dlist_init.c\
		dlist_destroy.c\
		dlist_ins_next.c\
		dlist_ins_prev.c\
		dlist_remove.c\
		queue_init.c\
		queue_destroy.c\
		enqueue.c\
		dequeue.c\
		stack_push.c\
		stack_pop.c\
		comb.c\
		comb_u.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
INC = includes/libft.h

OBJDIR = bin/
HEADER = includes/

FLAGS = -Wall -Wextra -Werror

VPATH = src/ft_printf/:src/read/:src/memory/:src/print/:src/list/:src/str/:src/check/:src/tab/:src/number/:src/algo/:src/queue/:src/dlist/:src/stack/

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@
	@echo "Libft linked [\x1B[1;31mDone\x1B[0m]"

$(OBJDIR)%.o: %.c $(INC)
	@if ! [ -d $(OBJDIR) ]; then mkdir $(OBJDIR); fi
	@gcc -c $< $(FLAGS) -I $(HEADER) -o $@
	@echo "Compiling [\x1B[1;32m$<\x1B[0m]\r"

clean :
	@rm -f $(OBJ)
	@echo "\x1B[1;31mDeleting object files\x1B[0m"
	@if [ -d $(OBJDIR) ]; then rm -rf $(OBJDIR); fi

fclean : clean
	@rm -f $(NAME)
	@echo "\x1B[1;31mDeleting Libft.a\x1B[0m"
	@if [ -d $(OBJDIR) ]; then rm -rf $(OBJDIR); fi

re : fclean all

.PHONY : clean fclean all
