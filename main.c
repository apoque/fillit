/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 11:14:35 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:24:05 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char		**tetrissplit;
	t_tetris	*tetrisarray;
	int			nbtetris;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (!(tetrissplit = ft_splittetris(argv[1])))
	{
		ft_putstr("error\n");
		return (1);
	}
	nbtetris = ft_arraylen(tetrissplit);
	tetrisarray = ft_tetrisarray(tetrissplit, nbtetris);
	if (!(ft_validtetris(tetrisarray, nbtetris)))
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_solution(tetrisarray, nbtetris);
	return (0);
}
