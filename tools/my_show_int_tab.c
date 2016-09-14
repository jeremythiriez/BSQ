/*
** my_show_int_tab.c for my_show_int_tab.c in /home/thirie_a/tech_1/PSU_2015_my_printf
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Sun Apr 10 22:21:14 2016 jeremy thiriez
** Last update Mon May 23 15:19:22 2016 jeremy thiriez
*/

#include "bsq.h"

int	my_show_int_tab(t_bsq *bsq)
{
  int	i;
  int	j;

  i = 0;
  while (i < bsq->size_line)
    {
      j = 0;
      while (j < bsq->size_col)
	{
	  my_put_nbr(bsq->tab[i][j]);
	  if (bsq->tab[i][j] < 10)
	    my_putchar(' ');
	  my_putchar(' ');
	  ++j;
	}
      my_putchar('\n');
      ++i;
    }
  return (0);
}
