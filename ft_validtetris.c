/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validtetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:14:30 by apoque            #+#    #+#             */
/*   Updated: 2017/12/02 11:21:00 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_validtetris(t_tetris *tetrisarray, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		if (tetrisarray[i++].valid == 0)
			return (0);
	}
	return (1);
}
