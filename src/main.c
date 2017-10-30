#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1

#include <stdio.h>

int	ft_count_bufsize(char *doc)
{
	int	fd;
	int	nb;
	char	buf[BUF_SIZE];

	nb = 0;
	fd = open(doc, O_RDONLY);
	while (read(fd, buf, BUF_SIZE))
			nb++;
	close(fd);
	/*printf("il y a %d tetris\n",(nb+1)/21);*/ 
	return (nb); /*il y a en fait (nb+1)/5 tetris*/
}

void	ft_doc_to_char(char *doc)
{
	int	fd;
	char	*buf;
	int	nb;

	nb = ft_count_bufsize(doc);	
	/*printf("%d\n", nb);*/
	fd = open(doc, O_RDONLY);
	if(!(buf = (char *)malloc(sizeof(char) * (nb + 1))))
		ft_putstr("error memalloc\n");;
	read(fd, buf, nb);
	buf[ft_count_bufsize(doc) + 1] = '\0';
	close(fd);
	printf("%s", buf);
	ft_check_1(buf, nb);
}

int	main(int ac, char **av)
{

	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	ft_doc_to_char(av[1]);
	return (0);
}
