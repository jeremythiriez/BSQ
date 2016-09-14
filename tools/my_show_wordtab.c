/*
** my_show_wordtab.c for my_show_wordtab.c in /home/thirie_a/rendu/Piscine_C_J08/ex_03
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Wed Mar  9 11:57:39 2016 jeremy thiriez
** Last update Sun May 22 13:42:14 2016 jeremy thiriez
*/

#include "bsq.h"

int	my_show_wordtab(t_bsq *bsq)
{
  int	i;

  i = 0;
  while (bsq->map[i])
    {
      if (bsq->color == 1)
	my_put_color(bsq->map[i]);
      else
	my_putstr(bsq->map[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
