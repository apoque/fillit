#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_coor
{
	short	x;
	short	y;
}			t_coor;

typedef struct		s_tet
{
	t_coor	coor[4];
	short	num_tet;
	short	size_tet;
	char	name;
}			t_tet;

void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_check_1(char *doc, int nb);
void	ft_check_4(t_tet *tet, int tot_tet);
#endif
