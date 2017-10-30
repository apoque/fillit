NAME = fillit
HEADERS = -Wall -Wextra -Werror -c -Iincludes/

all : $(NAME)

objs :
	mkdir objs
	gcc $(HEADERS) src/*.c
	mv *.o objs

$(NAME) : objs
	gcc objs/*.o -o $(NAME)

clean :
	rm -rf objs

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
