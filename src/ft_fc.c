/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:21:30 by apoque            #+#    #+#             */
/*   Updated: 2017/11/16 12:21:32 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

#define SIZE tet[0].size_tet
#define X (tet[cur_tet].coor[i].x - tet[cur_tet].coor[0].x + tet[cur_tet].place.x)
#define Y (tet[cur_tet].coor[i].y - tet[cur_tet].coor[0].y + tet[cur_tet].place.y)

int	ft_check_place(t_tet *tet, int cur_tet, int a)
{
	int	i;
	int	stack;

	i = 0;
	stack = 0;
	while (i < 4)
	{
		if (a == 1)
			if (X <= SIZE * 4 - 1)
				stack++;
		if (a == 2)
			if (Y <= SIZE * 4 - 1)
				stack++;
		i++;
	}
	if (stack == 4)
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 && s2)
	{
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		return (*s1 - *s2);
	}
	return (0);
}

int	ft_length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_length(str));
}
