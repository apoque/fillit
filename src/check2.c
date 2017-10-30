#include "fillit.h"

#define x1 tet[i].coor[j].x
#define y1 tet[i].coor[j].y
#define x2 tet[i].coor[k].x
#define y2 tet[i].coor[k].y

#include <stdio.h>

int	ft_count_touchs(t_tet *tet, int i, int j) /*compte le nb de contact entre # et ses voisins */
{
	int	k;
	int	touchs;

	k = -1;
	touchs = 0;
	while (k++ <= 2)
	{
		if (k == j)
			k++;
		if (x1 == x2 && ((y1 - y2 == 1) || (y2 - y1 == 1)))
			touchs++;
		if (y1 == y2 && ((x1 - x2 == 1) || (x2 - x1 == 1)))
			touchs++;
	}
	return (touchs);
}

int	ft_check_5(t_tet *tet, int tot_tet) /*check position des differents #*/
{
	int	i;
	int	j;
	int	touch;
	int	count_1_touch;

	i = -1;
	while (i++ < tot_tet - 1)
	{
		j = -1;
		count_1_touch = 0;
		while (j++ <= 2)
		{
			touch = ft_count_touchs(tet, i, j);
				/*printf("il y a %d touches pour le %de # du %d tetris\n", touch, j+1, i+1);*/
			if (touch == 0)
			       	return (0);
			if (touch == 1)
				count_1_touch++;
			if (touch == 3)
				count_1_touch--;
		}
		if (count_1_touch > 2)
		{
			/*printf("il y a %d # a une touche dans le %de tetris\n", count_1_touch, i + 1);*/
			return (0);
		}
	}
	return (1);
}

void	ft_check_4(t_tet *tet, int tot_tet) /*check du nb de # */
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	while (i < tot_tet)
	{
		/*printf("il y a %d # dans le %de tetris\n", tet[i].size_tet, i);*/
		if (tet[i].size_tet != 4)
		{
			a = 0;
			printf("pb de nb de #\n");
		}
		i++;
	}
	if (a == 1)
		a = ft_check_5(tet, tot_tet);
	if (a == 0)
		ft_putstr("error\n");
	else
		ft_putstr("VICTOIIIIIRE\n"); /*prochaine ft */
}
