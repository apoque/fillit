/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:17:48 by apoque            #+#    #+#             */
/*   Updated: 2017/11/21 11:27:29 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"
#include <unistd.h>

#define C coor
#define SIZE tet[0].size_tet
#define X (tet[cur_tet].C[i].x - tet[cur_tet].C[0].x + tet[cur_tet].place.x)
#define Y (tet[cur_tet].C[i].y - tet[cur_tet].C[0].y + tet[cur_tet].place.y)

int		ft_check_letter(char grid, t_tet *tet, int cur_tet)
{
	int	i;
	int	stack;

	i = cur_tet;
	stack = 0;
	while (i < SIZE)
	{
		if (grid == tet[i].name)
			stack++;
		i++;
	}
	if (stack > 0)
		return (1);
	else
		return (0);
}

int		ft_check_grid_bis(char **grid, t_tet *tet, int cur_tet)
{
	//printf("debut ft_check_grid_bis\n");
	int	i;
	int	stack;
	int	x;
	int	y;

	i = 0;
	stack = 0;
	while (i < 4)
	{
		if (X == SIZE * 4 - 1)/*pb avec les changements de X ?*/
		{
			x = 0;
			y = Y + 1;
		}
		else
		{
			x = X + 1;
			y = Y;
		}
		//printf("x = %d\ny = %d\n", x, y);
		if (y == SIZE * 4 - 1 && (grid[y][x] != '.' && ft_check_letter(grid[y][x], tet, cur_tet) == 0))
				stack++;
		if (y > SIZE * 4 - 1)
			stack++;
		i++;
	}
	//printf("fin ft_check_grid_bis\n");
	if (stack > 0)
		return (0);
	else
		return (1);
}

void	ft_cpy_grid(char ***grids, char **grid, t_tet *tet)
{
	int	i;
	int	j;

	i = 0;
	while (i <= SIZE * 4 - 1)
	{
		j = 0;
		while (j <= SIZE * 4 - 1)
		{
			if (grids[1][i][j] != grid[i][j])
				grids[1][i][j] = grid[i][j];
			j++;
		}
		i++;
	}
}

int		ft_empty_grid(char **grid, t_tet *tet)
{
	int	i;
	int	j;

	i = 0;
	while (i <= SIZE * 4 - 1)
	{
		j = 0;
		while (j <= SIZE * 4 - 1)
		{
			if (grid[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_aff_grid(char **grid, t_tet *tet)
{
	//printf("debut aff_grid\n");
	int	i;

	i = 0;
	while (i <= SIZE * 4 - 1)
	{
		ft_putstr(grid[i]);
		write(1, "\n", 1);
		i++;
	}
	//printf("fin aff_grid\n");
}
