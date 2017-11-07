#include "fillit.h"
#include <stdlib.h>

#define SIZE tet[0].size_tet
#define X (tet[cur_tet].coor[i].x - tet[cur_tet].coor[0].x + tet[cur_tet].place.x)
#define Y (tet[cur_tet].coor[i].y - tet[cur_tet].coor[0].y + tet[cur_tet].place.y)

#include <stdio.h>

void	ft_remove_tet(char ***grids, t_tet *tet, int cur_tet)
{
	int	i;
	int	j;

	i = 0;
	while (i <= SIZE * 4 - 1)
	{
		j = 0;
		while (j <= SIZE * 4 - 1)
		{
			if (grids[0][i][j] == tet[cur_tet].name)
				grids[0][i][j] = '.';
			j++;
		}
		i++;
	}
	/*i = 0;
	while (i < 4)
	{
		grids[0][Y][X] = '.';
		i++;
	}*/
}

int	**ft_init_dim(void)
{
	int	**dim;
	int	i;
	int	j;

	i = 0;
	if (!(dim = (int **)malloc(sizeof(int *) * 2)))
		return (NULL);
	while (i != 2)
	{
		j = 0;
		if (!(dim[i] = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
		while (j != 4)
		{
			dim[i][j] = 0;
			j++;
		}
		i++;
	}
	return (dim);
}

int	*ft_cmp_dim(int *dim, int i, int j)
{
	if (j < dim[0])
		dim[0] = j;
	if (j > dim[2])
		dim[2] = j;
	if (i < dim[1])
		dim[1] = i;
	if (i > dim[3])
		dim[3] = i;
	return (dim);
}

int	*ft_dim(char **grid, int *dim, t_tet *tet)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i][0] == '.')
	{
		j = 0;
		while (grid[i][j] == '.')
			j++;
		i++;
	}
	dim[0] = j;
	dim[1] = i;
	i = 0;
	while (i <= SIZE * 4 - 1)
	{
		j = 0;
		while (j <= SIZE * 4 - 1)
		{
			if (grid[i][j] != '.')
				dim = ft_cmp_dim(dim, i, j);
			j++;
		}
		i++;
	}
	return (dim);
}

char	**ft_cmp_grid(char **grid1, char **grid2, t_tet *tet)
{
	int	**dim;
	int	i;
	int	*size;

	if (ft_empty_grid(grid2, tet) == 1)
		return (grid1);
	dim = ft_init_dim();
	dim[0] = ft_dim(grid1, dim[0], tet);
	dim[1] = ft_dim(grid2, dim[1], tet);
	i = 0;
	if (!(size = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	while (i < 2)
	{
		if (dim[i][2] - dim[i][0] > dim[i][3] - dim[i][1])
			size[i] = dim[i][2] - dim[i][0] + 1;
		else
			size[i] = dim[i][3] - dim[i][1] + 1;
		i++;
	}
	/*printf("\n//////////////////////\n\nsize 1 = %d\nsize 2 = %d\n\n///////////////////////////\n", size[0], size[1]);*/
	free(dim);
	if (size[0] >= size[1])
	{
		/*printf("1\n");*/
		return (grid2);
	}
	else
	{
		/*printf("2\n");*/
		return (grid1);
	}
	/*free(size);*/
}
