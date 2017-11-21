/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:21:46 by apoque            #+#    #+#             */
/*   Updated: 2017/11/16 12:21:51 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_end_tet(t_tet *tet, int cur_tet)
{
	int	i;
	int	stack;

	i = 0;
	stack = 0;
	if (cur_tet > 0)
	{
		while (i < cur_tet - 1)
		{
			if (tet[cur_tet].place.y > tet[i].place.y + 4)
				stack++;
			i++;
		}
		if (stack == cur_tet)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
