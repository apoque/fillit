#include "fillit.h"
#include <stdlib.h>

#include <stdio.h>

/*void	ft_aff_coor(t_tet *tet, int tot_tet)
{
	int	i;
	int	j;

	i = 0;
	while (i <= tot_tet - 1)
	{
		printf("\n[[[[[[[[[[  TET N* %d  ]]]]]]]]]]\n", i + 1);
		printf("char = %c\n", tet[i].name);
		printf("size = %d\n", tet[i].size_tet);
		j = 0;
		while (j <= 3)
		{
			printf("---%de #---\n", j + 1);
			printf("x = %d\n", tet[i].coor[j].x);
			printf("y = %d\n", tet[i].coor[j].y);
			j++;
		}
		i++;
	}
}*/

t_tet	*ft_init_tets(int tot_tet)
{
	t_tet	*tets;
	t_coor	*coord;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(tets = (t_tet *)malloc(sizeof(t_tet) * tot_tet)))
		return (NULL);
	while (i++ <= tot_tet - 1)
	{
		tets[i].num_tet = 0;
		tets[i].size_tet = 0;
		tets[i].name = 0;
		while (j <= 4)
		{
			if(!(coord = (t_coor *)malloc(sizeof(t_coor))))
				return (NULL);
			coord->x = 0;
			coord->y = 0;
			tets[i].coor[j] = *coord;
			j++;
		}
	}
	return (tets);
}

t_tet	*ft_fill_tet(t_tet *tet, int cur_tet, short x, short y)
{
	tet[cur_tet - 1].num_tet = cur_tet;
	tet[cur_tet - 1].size_tet++;
	tet[cur_tet - 1].name = 'A' + cur_tet - 1;
	if (tet[cur_tet - 1].size_tet <= 4)
	{
		tet[cur_tet - 1].coor[tet[cur_tet - 1].size_tet - 1].x = x;
		tet[cur_tet - 1].coor[tet[cur_tet - 1].size_tet - 1].y = y;
	}
	return (tet);
}

int	ft_check_3(char *doc, int cur_tet, int line, t_tet *tet) /*ft de check de ligne de tetris*/
{
	int	col;
	int	a;

	col = 1;
	a = 1;
	while (col <= 4 && a == 1) /*col = 4 -> fin de ligne*/
	{
		if (doc[(line - cur_tet) * 5 + col + cur_tet - 2] == '.')
			col++;
		else
		{
			if (doc[(line - cur_tet) * 5 + col + cur_tet - 2] == '#')
			{
				tet = ft_fill_tet(tet, cur_tet, col, line - 5 * (cur_tet - 1));
					col++;
			}
			else
			{
				/*printf("error2\ncol = %d\nline = %d\ncur_tet = %d\nchar = %c\nemplacement = %d\n", col, line, cur_tet, doc[(line-cur_tet)*5+col+cur_tet-2], (line-cur_tet)*5+col+cur_tet-2);*/
				a = 0;
			}
		}

	}
	if (doc[(line - cur_tet) * 5 + col +cur_tet - 2] != '\n') /*check dernier caractere*/
	{
		/*printf("error3\ncol = %d\nchar = %c\nemplacement = %d\n", col, doc[(line-cur_tet)*5+col+cur_tet-2], (line-cur_tet)*5+col+cur_tet-2);*/
		a = 0;
	}
	return (a);
}	

int	ft_check_2(char *doc, int cur_tet, int line, t_tet *tet)
{
	int	a;

	a = 1;
	if (line % 5 == 0) /*si ligne inter-tetris*/
	{
		if (doc[(line - cur_tet + 1) * 5 + cur_tet - 2] != '\n')
		{
			/*printf("error1\n col = %c", doc[(line-cur_tet+1)*5+cur_tet-2]);*/
			a = 0;
		}
	}
	else
	{
		a = ft_check_3(doc, cur_tet, line, tet);
	}
	return (a);
}

void	ft_check_1(char *doc, int nb)
{
	int	line;
	int	tot_tet;
	int	cur_tet;
	int	a;
	t_tet	*tet;

	line = 1;
	a = 1;
	if ((nb + 1) % 21 != 0) /*verif bon nb de caracteres*/
		a = 0;
	tot_tet = (nb + 1) / 21; /*nb de tetris total*/
	tet = ft_init_tets(tot_tet);
	/*printf("nb = %d\ntot_tet = %d\n", nb, tot_tet);*/
	while (line <= tot_tet * 5 - 1 && a == 1) /*nb de ligne au totale*/
	{
		cur_tet = line / 5 + 1; /*numero du tetris courrant*/
		a = ft_check_2(doc, cur_tet, line, tet); /*check ligne courrante*/
		line++;
		if (a == 0)
			break;
	}
	if (a == 1)
	{
		/*printf("VICTOIIIIIIRE\n");*/
		/*ft_aff_coor(tet, tot_tet);*/
		ft_check_4(tet, tot_tet);
	}
	else
		ft_putstr("error\n");
}
