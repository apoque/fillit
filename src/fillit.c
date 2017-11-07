#include "fillit.h"

#define SIZE tet[0].size_tet
#define X (tet.coor[i].x - tet.coor[0].x + tet.place.x)
#define Y (tet.coor[i].y - tet.coor[0].y + tet.place.y)

#include <stdio.h>

int	ft_arret(char **grid, t_tet *tet, int tot_tet)/*check si tous les "places sont au max"*/
{
	int	i;
	int	stack;

	i = 0;
	stack = 0;
	while (i < tot_tet)
	{
		/*if (tet[i].place.x == SIZE * 4 - 1 && tet[i].place.y == SIZE * 4 - 1)*/
		if (ft_check_grid_bis(grid, tet, i) == 0)
			stack++;
		i++;
	}
	if (stack == tot_tet)
		return (0);
	else
		return (1);
}

int	ft_check_grid(char **grid, t_tet tet, int tot_tet)/*check que les 4 emplacements sont libress et existent*/
{
	int	i;
	int	stack;

	i = 0;
	stack = 0;
	while (i < 4)
	{
		if (X <= tot_tet * 4 - 1 && Y <= tot_tet * 4 - 1 && grid[Y][X] == '.')
			stack++;
		i++;
	}
	if (stack == 4)
		return (1);
	else
		return (0);
}

int	ft_chg_tet_place(t_tet *tet, int cur_tet, char ***grids)
{
	if (ft_end_tet(tet, cur_tet) == 1)
	{
		if (tet[cur_tet].place.x < SIZE * 4 - 1)
			tet[cur_tet].place.x++;
		else
		{
			if (tet[cur_tet].place.y < SIZE * 4 - 1)
			{
				tet[cur_tet].place.x = 0;
				tet[cur_tet].place.y++;
			}
			else
			{
				if (cur_tet > 0 && ft_arret(grids[0], tet, SIZE) == 1)
				{
					ft_remove_tet(grids, tet, cur_tet);
					tet[cur_tet].place.x = 0;
					tet[cur_tet].place.y = 0;
					cur_tet--;
					ft_remove_tet(grids, tet, cur_tet);
					ft_chg_tet_place(tet, cur_tet, grids);
				}
			}
		}
	}
	else
	{
		tet[cur_tet].place.x = SIZE * 4 - 1;
		tet[cur_tet].place.y = SIZE * 4 - 1;
	}
	return (cur_tet);
}

char	**ft_place_tet(char **grid, t_tet *tets, int cur_tet)/*on place le cur_tet sur la grille*/
{
	int	i;
	t_tet	tet;

	i = 0;
	tet = tets[cur_tet];
	/*ft_mv_tet(grids[0], tet[cur_tet], SIZE)*/
	while (i < 4)
	{
		grid[Y][X] = tet.name;
		i++;
	}
	return (grid);
}

void	ft_fillit(t_tet *tet, char ***grids, int cur_tet)
{
	/*printf("Place du %de tet :\nx = %d\ny = %d\n\n", cur_tet, tet[cur_tet].place.x, tet[cur_tet].place.y);*/
	/*printf("ft_arret = %d\n\n",ft_arret(grids[0], tet, SIZE));*/
	if (ft_arret(grids[0], tet, SIZE) != 1)
	{
		ft_aff_grid(grids[1], tet);
		/*printf("ft_arret = %d\n", ft_arret(grids[0], tet, SIZE));*/
		/*ft_aff_grid(grids[0], tet);*/
	}
	if (ft_arret(grids[0], tet, SIZE) == 1)
	{
		while (cur_tet < SIZE)
		{
			if (ft_check_grid(grids[0], tet[cur_tet], SIZE) == 1)
			{
				grids[0] = ft_place_tet(grids[0], tet, cur_tet);
				cur_tet++;
			}
			else
			{
				if (ft_arret(grids[0], tet, SIZE) == 1)
					cur_tet = ft_chg_tet_place(tet, cur_tet, grids);
				else
					break;
			}

			ft_fillit(tet, grids, cur_tet);
		}
		if (ft_arret(grids[0], tet, SIZE) == 1)
		{
			cur_tet--;
			/*printf("Place du %de tet :\nx = %d\ny = %d\n\ngrid1 =\n", cur_tet, tet[cur_tet].place.x, tet[cur_tet].place.y);*/
			ft_aff_grid(grids[0], tet);
			/*printf("ft_arret = %d\n", ft_arret(grids[0], tet, SIZE));
			printf("\n\ngrid2 =\n");
			ft_aff_grid(grids[1], tet);*/
			printf("\n\n\n-----------------------\n\n\n");
			ft_cpy_grid(grids, ft_cmp_grid(grids[0], grids[1], tet), tet);
			ft_remove_tet(grids, tet, cur_tet);
			cur_tet = ft_chg_tet_place(tet, cur_tet, grids);
			ft_fillit(tet, grids, cur_tet);
		}
	}
}
