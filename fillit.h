/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:55:43 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 12:32:16 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# define TET_SIZE 20
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_tetris
{
	char				family;
	int					valid;
	int					islast;
	int					widthright;
	int					widthleft;
	int					height;
	struct s_position	*pos;
}				t_tetris;

typedef struct	s_table
{
	int		size;
	char	**content;
}				t_table;

typedef struct	s_position
{
	int x;
	int y;
}				t_position;

int				ft_abs(int n);
char			**ft_newtable(int size);
t_tetris		ft_newtetris();
char			**ft_tablecpy(char **s, int size);
void			ft_putstr(char *s);
void			ft_putchar(char c);
char			**ft_splittetris(char *filename);
int				ft_arraylen(char **array);
t_tetris		*ft_tetrisarray(char **s, int nb);
int				ft_validtetris(t_tetris *tetrisarray, int nb);
int				ft_sqrtround(int n);
void			ft_solution(t_tetris *array, int nbtetris);
void			ft_printtable(char **s);
int				ft_placeable(t_tetris *tetris, t_table table, int i, int j);
int				ft_place(t_tetris *tetris, t_table table);
int				ft_strlen(char *str);
int				ft_check_1(char *str, int size);

#endif
