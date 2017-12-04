/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:13:46 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:19:48 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		ft_placeable(t_tetris *t, t_table table, int i, int j)
{
	int		k;
	t_table	cpy;

	cpy.size = table.size;
	cpy.content = ft_tablecpy(table.content, table.size);
	k = -1;
	while (k++ < 3)
	{
		if (cpy.content[t->pos[k].y + i][t->pos[k].x + j] != '.')
		{
			free(cpy.content);
			return (0);
		}
		else
			cpy.content[t->pos[k].y + i][t->pos[k].x + j] = t->family;
	}
	if (t->islast)
	{
		ft_printtable(cpy.content);
		return (1);
	}
	else
		return (ft_place(t + 1, cpy));
}

int		ft_place(t_tetris *tetris, t_table table)
{
	int	i;
	int	j;
	int	size;

	size = table.size;
	i = 0;
	j = ft_abs(tetris->widthleft);
	while (i < size - tetris->height)
	{
		j = ft_abs(tetris->widthleft);
		while (j < size - tetris->widthright)
		{
			if (ft_placeable(tetris, table, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_solution(t_tetris *array, int nbtetris)
{
	t_table	table;
	int		size;

	size = ft_sqrtround(4 * nbtetris);
	table.content = ft_newtable(size);
	table.size = size;
	while (!ft_place(array, table))
	{
		table.content = ft_newtable(++size);
		table.size = size;
	}
}
