/*
** bsq.h for bsq.h in /home/thirie_a/tech_1/C_Prog_Elem/CPE_2015_BSQ
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Apr 25 18:28:40 2016 jeremy thiriez
** Last update Sun May 22 14:13:18 2016 jeremy thiriez
*/

#ifndef _BSQ_H_
# define _BSQ_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

typedef struct	s_ct
{
  int		i;
  int		j;
  int		save_y;
  int		save_x;
  int		save_size;
  int		save_left;
  int		save_up;
  int		save_diag;
}		t_ct;

typedef struct	s_bsq
{
  char		**map;
  char		*buff;
  int		count_first_line;
  int		size_col;
  int		size_line;
  int		**tab;
  int		color;
  int		ret;
  t_ct		ct;
}		t_bsq;

int		malloc_my_int_tab(t_bsq *bsq);
void		make_square(t_bsq *bsq);
void		my_init_bsq(t_bsq *bsq);
void		my_count_col_and_line(t_bsq *bsq);
int		my_malloc_map(t_bsq *bsq);
char		*read_map(char **av, t_bsq *bsq);
int		my_split(t_bsq *bsq);
int		my_find_wall(t_bsq *bsq);
int		my_getnbr(char *str);
char		*my_strcpy(char *s1, char *s2);
void		my_putchar(char c);
int		my_putstr(char *str);
int		my_put_nbr(int nb);
int		my_show_int_tab(t_bsq *bsq);
int		my_put_error(char *str);
int		my_show_wordtab(t_bsq *bsq);
int		my_put_color(char *str);
int		my_strcmp(char *s1, char *s2);

#endif /* !_BSQ_H_ */
