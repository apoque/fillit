/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:14:17 by apoque            #+#    #+#             */
/*   Updated: 2017/12/02 11:37:01 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tablecpy(char **str, int size)
{
	char	**newtable;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(newtable = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	newtable[size] = NULL;
	while (i < size)
	{
		if (!(newtable[i] = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		newtable[i][size] = '\0';
		while (j < size)
		{
			newtable[i][j] = str[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	return (newtable);
}
