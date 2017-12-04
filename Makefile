CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

INC = fillit.h

SRC =	main.c \
		ft_abs.c\
		ft_arraylen.c\
		ft_newtable.c\
		ft_tetrisarray.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_splittetris.c\
		ft_sqrtround.c\
		ft_validtetris.c\
		ft_solution.c\
		ft_printtable.c\
		ft_tablecpy.c\
		ft_check.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
