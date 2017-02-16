# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                   \\             #
#                                                               (o >           #
#    By: cpoulet <cpoulet@student.42.fr>                     \\_//)            #
#                                                             \_/_)            #
#    Created: 2017/01/22 14:13:52 by cpoulet                   _|_             #
#    Updated: 2017/02/16 18:00:59 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin
SRC = lemin.c\
		parser.c\
		find_path.c\
		flux.c

OTHER = \

INC = includes/lemin.h
OBJPATH = bin/
OBJ = $(addprefix $(OBJPATH), $(SRC:.c=.o))
VPATH = srcs/

INCLUDES = -I includes/ -I libft/includes/
LIBS = -L libft/ -lft
PLS = -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(PLS)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "\x1B[1;31mCreation de la Fourmiliere...\x1B[0m"

$(OBJPATH)%.o : %.c $(INC)
	@if ! [ -d $(OBJPATH) ]; then mkdir $(OBJPATH); fi
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling [\x1B[1;32m$<\x1B[0m]\r"

clean :
	@rm -f $(OBJ)
	@echo "\x1B[1;31mDeleting objects...\x1B[0m"
	@make clean -C libft/
	@if [ -d $(OBJPATH) ]; then rm -rf $(OBJPATH); fi

fclean : clean
	@rm -f $(NAME)
	@echo "\x1B[1;31mDeleting Lemin\x1B[0m"
	@make fclean -C libft/
	@if [ -d $(OBJPATH) ]; then rm -rf $(OBJPATH); fi

re : fclean all

lib :
	@make -C libft/
	@make clean -C libft/

.PHONY : all clean fclean re
