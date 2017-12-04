/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrisarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:14:22 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:32:50 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int		ft_counttouch(t_tetris *t, int n)
{
	int touch;
	int i;

	touch = 0;
	i = 0;
	while (i < 4)
	{
		if (i != n)
		{
			if ((ft_abs(t->pos[n].x - t->pos[i].x) == 1
				&& ft_abs(t->pos[n].y - t->pos[i].y) == 0)
				|| (ft_abs(t->pos[n].y - t->pos[i].y) == 1
				&& ft_abs(t->pos[n].x - t->pos[i].x) == 0))
				touch++;
		}
		i++;
	}
	return (touch);
}

static int		ft_valid(t_tetris *t, int n)
{
	int j;
	int touch;
	int countonetouch;

	if (n != 4)
		return (0);
	j = 0;
	countonetouch = 0;
	while (j < 4)
	{
		touch = ft_counttouch(t, j);
		if (touch == 0)
			return (0);
		if (touch == 1)
			countonetouch++;
		if (touch == 3)
			countonetouch--;
		j++;
	}
	if (countonetouch > 2)
		return (0);
	return (1);
}

static void		ft_filltetris(t_tetris *new, int l, int h, int *n)
{
	int i;

	i = 4;
	new->pos[*n].x = l;
	new->pos[*n].y = h;
	if (*n == 3)
	{
		while (i--)
		{
			new->pos[i].x = new->pos[i].x - new->pos[0].x;
			if (new->pos[i].x > new->widthright)
				new->widthright = new->pos[i].x;
			if (new->pos[i].x < new->widthleft)
				new->widthleft = new->pos[i].x;
			new->pos[i].y = new->pos[i].y - new->pos[0].y;
			if (ft_abs(new->pos[i].y) > new->height)
				new->height = ft_abs(new->pos[i].y);
		}
	}
}

static t_tetris	ft_inittetris(char *s)
{
	t_tetris	new;
	int			i;
	int			j;
	int			n;

	i = 0;
	j = 0;
	n = 0;
	new = ft_newtetris();
	while (*s)
	{
		if (*s == '#')
		{
			ft_filltetris(&new, i, j, &n);
			n++;
		}
		j += (*s == '\n' ? 1 : 0);
		i = (*s == '\n' ? 0 : i);
		i += (*s != '\n' ? 1 : 0);
		s++;
	}
	new.valid = ft_valid(&new, n);
	return (new);
}

t_tetris		*ft_tetrisarray(char **s, int nb)
{
	int			c;
	int			i;
	t_tetris	*tetrisarray;

	i = 0;
	tetrisarray = (t_tetris *)malloc(sizeof(t_tetris) * nb);
	c = 'A';
	while (i < nb)
	{
		tetrisarray[i] = ft_inittetris(*s);
		tetrisarray[i].family = c++;
		tetrisarray[i].islast = 0;
		i++;
		s++;
	}
	tetrisarray[i - 1].islast = 1;
	return (tetrisarray);
}
