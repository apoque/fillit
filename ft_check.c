/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:08:23 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:24:37 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int	ft_check_3(char *doc, int cur_tet, int line)
{
	int	col;
	int	a;
	int	nb_diez;

	col = 1;
	a = 1;
	nb_diez = 0;
	while (col <= 4 && a == 1)
	{
		if (doc[(line - cur_tet) * 5 + col + cur_tet - 2] == '.')
			col++;
		else
		{
			if (doc[(line - cur_tet) * 5 + col + cur_tet - 2] == '#')
				col++;
			else
				a = 0;
		}
	}
	if (doc[(line - cur_tet) * 5 + col + cur_tet - 2] != '\n')
		a = 0;
	return (a);
}

int	ft_check_2(char *doc, int cur_tet, int line)
{
	int	a;

	a = 1;
	if (line % 5 == 0)
	{
		if (doc[(line - cur_tet + 1) * 5 + cur_tet - 2] != '\n')
			a = 0;
	}
	else
		a = ft_check_3(doc, cur_tet, line);
	return (a);
}

int	ft_check_1(char *doc, int nb)
{
	int	line;
	int	tot_tet;
	int	cur_tet;
	int	a;

	line = 1;
	a = 1;
	if ((nb + 1) % 21 != 0)
		a = 0;
	tot_tet = (nb + 1) / 21;
	while (line <= tot_tet * 5 - 1 && a == 1)
	{
		cur_tet = line / 5 + 1;
		a = ft_check_2(doc, cur_tet, line);
		line++;
		if (a == 0)
			break ;
	}
	if (a == 1)
		return (tot_tet);
	else
		return (0);
}
