/*
** my_bsq_algo.c for my_bsq_algo.c in /home/thirie_a/tech_1/C_Prog_Elem/CPE_2015_BSQ
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Tue Apr 26 00:08:24 2016 jeremy thiriez
** Last update Sun May 22 14:33:24 2016 jeremy thiriez
*/

#include "bsq.h"

void	set_free_zone2(t_bsq *bsq)
{
  bsq->ct.save_left = bsq->tab[bsq->ct.i][bsq->ct.j - 1];
  bsq->ct.save_up = bsq->tab[bsq->ct.i - 1][bsq->ct.j];
  bsq->ct.save_diag = bsq->tab[bsq->ct.i - 1][bsq->ct.j - 1];
  if (bsq->ct.save_left != 0 && bsq->ct.save_diag != 0 && bsq->ct.save_up != 0)
    {
      if (bsq->ct.i > 0 && bsq->ct.j > 0 &&
	  bsq->ct.save_left != 0 && bsq->ct.save_left <= bsq->ct.save_diag &&
	  bsq->ct.save_left <= bsq->ct.save_up)
	bsq->tab[bsq->ct.i][bsq->ct.j] = bsq->ct.save_left + 1;
      else if (bsq->ct.i > 0 && bsq->ct.j > 0 &&
	       bsq->ct.save_diag != 0 && bsq->ct.save_diag <= bsq->ct.save_up &&
	       bsq->ct.save_diag <= bsq->ct.save_left)
	bsq->tab[bsq->ct.i][bsq->ct.j] = bsq->ct.save_diag + 1;
      else if (bsq->ct.i > 0 && bsq->ct.j > 0 &&
	       bsq->ct.save_up != 0 && bsq->ct.save_up <= bsq->ct.save_diag &&
	       bsq->ct.save_up <= bsq->ct.save_left)
	bsq->tab[bsq->ct.i][bsq->ct.j] = bsq->ct.save_up + 1;
    }
  else
    bsq->tab[bsq->ct.i][bsq->ct.j] = 1;
}

void	set_free_zone(t_bsq *bsq)
{
  if (bsq->ct.i == 0 || bsq->ct.j == 0)
    bsq->tab[bsq->ct.i][bsq->ct.j] = 1;
  else
    set_free_zone2(bsq);
  if (bsq->ct.save_size < bsq->tab[bsq->ct.i][bsq->ct.j])
    {
      bsq->ct.save_x = bsq->ct.j;
      bsq->ct.save_y = bsq->ct.i;
      bsq->ct.save_size = bsq->tab[bsq->ct.i][bsq->ct.j];
    }
}

int	malloc_my_int_tab(t_bsq *bsq)
{
  int	i;

  i = 0;
  if ((bsq->tab = malloc(sizeof(int *) * bsq->size_line)) == 0)
    return (EXIT_FAILURE);
  while (i < bsq->size_line)
    {
      if ((bsq->tab[i] = malloc(sizeof(int) * bsq->size_col)) == 0)
	return (EXIT_FAILURE);
      ++i;
    }
  return (EXIT_SUCCESS);
}

int	my_find_wall(t_bsq *bsq)
{
  bsq->ct.i = 0;
  while (bsq->map[bsq->ct.i])
    {
      bsq->ct.j = 0;
      while (bsq->map[bsq->ct.i][bsq->ct.j])
	{
	  if (bsq->map[bsq->ct.i][bsq->ct.j] == 'o')
	    bsq->tab[bsq->ct.i][bsq->ct.j] = 0;
	  else if (bsq->map[bsq->ct.i][bsq->ct.j] == '.')
	    set_free_zone(bsq);
	  else
	    return (EXIT_FAILURE);
	  ++bsq->ct.j;
	}
      ++bsq->ct.i;
    }
  return (EXIT_SUCCESS);
}

void	make_square(t_bsq *bsq)
{
  int	x;
  int	y;

  y = bsq->ct.save_size;
  bsq->ct.i = bsq->ct.save_y;
  while (y > 0)
    {
      bsq->ct.j = bsq->ct.save_x;
      x = bsq->ct.save_size;
      while (x > 0)
	{
	  bsq->map[bsq->ct.i][bsq->ct.j] = 'x';
	  --x;
	  --bsq->ct.j;
	}
      --bsq->ct.i;
      --y;
    }
}
