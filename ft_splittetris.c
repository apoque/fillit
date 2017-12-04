/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:30:03 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:37:33 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int	ft_nbtetris(char *s)
{
	int nbtetris;

	nbtetris = ft_check_1(s, ft_strlen(s));
	if (nbtetris > 26 || nbtetris == 0)
		return (0);
	return (nbtetris);
}

static char	*ft_readfile(char *filename)
{
	int		fd;
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	if (buff[ret - 1] == '\n' && buff[ret - 2] == '\n')
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (buff);
}

char		**ft_splittetris(char *filename)
{
	char	**split;
	char	*s;
	int		i;
	int		j;

	if (!(s = ft_readfile(filename)) || !ft_nbtetris(s)
		|| !(split = (char **)malloc((ft_nbtetris(s) + 1) * sizeof(char*))))
		return (NULL);
	split[ft_nbtetris(s)] = NULL;
	i = 0;
	j = -1;
	while (*s)
	{
		if (!i)
		{
			split[++j] = (char *)malloc(sizeof(char) * (TET_SIZE + 1));
			split[j][TET_SIZE] = '\0';
			s += (*s == '\n' ? 1 : 0);
		}
		split[j][i] = *(s++);
		i = (i == 19 ? -1 : i);
		i++;
	}
	return (split);
}
