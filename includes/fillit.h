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
	t_coor	place;
	char	name;
}			t_tet;

void	ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
void	ft_check_1(char *doc, int nb);
void	ft_check_4(t_tet *tet, int tot_tet);
int	ft_empty_grid(char **grid, t_tet *tet);
void	ft_fillit(t_tet *tet, char ***grids, int cur_tet);
char	**ft_cmp_grid(char **grdi1, char **grid2, t_tet *tet);
void	ft_cpy_grid(char ***grids, char **grid, t_tet *tet);
void	ft_aff_grid(char **grid, t_tet *tet);
void	ft_remove_tet(char ***grids, t_tet *tet, int cur_tet);
int	ft_end_tet(t_tet *tet, int cur_tet);
int	ft_check_place(t_tet *tet, int cur_tet, int a);
int	ft_check_grid_bis(char **grid, t_tet *tet, int cur_tet);
#endif
