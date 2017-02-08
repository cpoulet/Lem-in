# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                   \\             #
#                                                               (o >           #
#    By: cpoulet <cpoulet@student.42.fr>                     \\_//)            #
#                                                             \_/_)            #
#    Created: 2017/01/22 14:13:52 by cpoulet                   _|_             #
#    Updated: 2017/02/08 17:21:58 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin
FILES = lemin.c\
		parser.c\
		find_path.c\
		flux.c

OTHER = \

SRC_PATH = srcs/
SRC = $(addprefix srcs/,$(FILES))
OBJ = $(FILES:.c=.o)

INCLUDES = -I includes/ -I libft/includes/
LIBS = -L libft/ -lft
PLS = -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(PLS)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@echo "Compiling libft.a... OK"
	@gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Creation de la Fourmiliere... OK"

%.o : $(SRC_PATH)%.c includes/lemin.h
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@echo "Deleting objects... OK"
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

lib :
	@make -C libft/
	@make clean -C libft/

.PHONY : all clean fclean re
