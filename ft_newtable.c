/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:13:16 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:30:04 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_newtable(int size)
{
	char	**newtable;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(newtable = (char**)malloc((size + 1) * sizeof(char*))))
		return (NULL);
	newtable[size] = NULL;
	while (i < size)
	{
		if (!(newtable[i] = (char*)malloc((size + 1) * sizeof(char))))
			return (NULL);
		newtable[i][size] = '\0';
		while (j < size)
		{
			newtable[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (newtable);
}

t_tetris	ft_newtetris(void)
{
	t_tetris new;

	new.widthright = 0;
	new.widthleft = 0;
	new.height = 0;
	new.pos = (t_position *)malloc(4 * sizeof(t_position));
	return (new);
}
