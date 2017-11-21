/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:19:59 by apoque            #+#    #+#             */
/*   Updated: 2017/11/21 13:06:51 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SIZE tet[0].size_tet
#define X (tet.coor[i].x - tet.coor[0].x + tet.place.x)
#define Y (tet.coor[i].y - tet.coor[0].y + tet.place.y)

#include <stdio.h>
#include <unistd.h>

int		ft_arret(char **grid, t_tet *tet, int tot_tet)
{
	//printf("debut ft_arret\n");
	//ft_aff_grid(grid, tet);
	int	i;
	int	stack;

	i = 0;
	stack = 0;
	while (i < tot_tet)/* -1 ou pas ?*/
	{
		/*if (tet[i].place.x == SIZE * 4 - 1 && tet[i].place.y == SIZE * 4 - 1)*/
		if (ft_check_grid_bis(grid, tet, i) == 0)
			stack++;
		i++;
	}
	//printf("stack = %d\n", stack);
	//printf("fin ft_arret\n");
	if (stack == tot_tet)
		return (0);
	else
		return (1);
}

int		ft_check_grid(char **grid, t_tet tet, int tot_tet)/*check que les 4 emplacements sont libress et existent*/
{
	//printf("debut ft_check_grid\n");
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
	//printf("fin ft_check_grid\n");
	if (stack == 4)
		return (1);
	else
		return (0);
}

int		ft_chg_tet_place(t_tet *tet, int cur_tet, char ***grids)
{
	printf("debut ft_chg_tet_place\n");
	/*if (ft_end_tet(tet, cur_tet) == 1)
	{*/
		if (ft_check_place(tet, cur_tet, 1) == 1)
			tet[cur_tet].place.x++;
		else
		{
			if (ft_check_place(tet, cur_tet, 2) == 1)
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
					//printf("C\n");
				}
			}
		}/*
	}
	else
	{
		tet[cur_tet].place.x = SIZE * 4 - 1;
		tet[cur_tet].place.y = SIZE * 4 - 1;
	}*/
	printf("fin ft_chg_tet_place\ncur_tet = %d\n", cur_tet);
	//ft_aff_grid(grids[0], tet);
	return (cur_tet);
}

char	**ft_place_tet(char **grid, t_tet *tets, int cur_tet)/*on place le cur_tet sur la grille*/
{
	//printf("debut ft_place_tet\n");
	int		i;
	t_tet	tet;

	i = 0;
	tet = tets[cur_tet];
	while (i < 4)
	{
		//printf("X = %d\nY = %d\n", X, Y);
		grid[Y][X] = tet.name;
		i++;
	}
	//printf("fin ft_place_tet\n");
	return (grid);
}

void	ft_fillit(t_tet *tet, char ***grids, int cur_tet)
{
	printf("debut fillit\n");
	printf("\ngrid1 =\n");
	printf("ca plante ici\n");
	ft_aff_grid(grids[0], tet);
	printf("\nft_arret = %d\n", ft_arret(grids[0], tet, SIZE));/*ca bugg ici*/
	printf("\n\ngrid2 =\n");
	ft_aff_grid(grids[1], tet);
	printf("\n\n\n-----------------------\n\n\n");
	//sleep(1);
	/*printf("Place du %de tet :\nx = %d\ny = %d\n\n", cur_tet, tet[cur_tet].place.x, tet[cur_tet].place.y);*/
	/*printf("ft_arret = %d\n\n",ft_arret(grids[0], tet, SIZE));*/
	if (ft_arret(grids[0], tet, SIZE) != 1)
	{
		printf("\n\n\n\n\n");
		//ft_aff_coor(tet, SIZE);
		printf("\n\n\n\n\n");
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
				{
					//printf("A'");
					cur_tet = ft_chg_tet_place(tet, cur_tet, grids); 
					//printf("A\n");
				}
				else
					break;
			}
			ft_fillit(tet, grids, cur_tet);
		}
		if (ft_arret(grids[0], tet, SIZE) == 1)
		{
			cur_tet--;
			/*printf("Place du %de tet :\nx = %d\ny = %d\n\n", cur_tet, tet[cur_tet].place.x, tet[cur_tet].place.y);*/
			ft_cpy_grid(grids, ft_cmp_grid(grids[0], grids[1], tet), tet);
			ft_remove_tet(grids, tet, cur_tet);
			cur_tet = ft_chg_tet_place(tet, cur_tet, grids);
			//printf("B\n");
			ft_fillit(tet, grids, cur_tet);
		}
	}
}
