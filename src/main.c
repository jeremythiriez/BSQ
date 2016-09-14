/*
** main.c for main.c in /home/thirie_a/tech_1/C_Prog_Elem/CPE_2015_BSQ
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Apr 25 23:41:51 2016 jeremy thiriez
** Last update Sun May 22 14:34:41 2016 jeremy thiriez
*/

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	my_init_bsq(t_bsq *bsq)
{
  bsq->ret = 0;
  bsq->count_first_line = 0;
  bsq->size_col = 0;
  bsq->size_line = 0;
  bsq->ct.save_size = 0;
  bsq->ct.save_x = 0;
  bsq->ct.save_y = 0;
  bsq->map = NULL;
  bsq->buff = NULL;
}

void	my_free(t_bsq *bsq)
{
  bsq->ct.i = 0;
  while (bsq->map[bsq->ct.i])
    {
      free(bsq->map[bsq->ct.i]);
      ++bsq->ct.i;
    }
  free(bsq->buff);
}

int	my_put_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i += 1;
    }
  return (EXIT_FAILURE);
}

void	check_flag(t_bsq *bsq, char *str)
{
  if (my_strcmp(str, "-color") == 0)
    bsq->color = 1;
  else
    bsq->color = 0;
}

int	main(int ac, char **av)
{
  t_bsq	bsq;

  (void)ac;
  my_init_bsq(&bsq);
  check_flag(&bsq, av[2]);
  if ((bsq.buff = read_map(av, &bsq)) == NULL)
    return (EXIT_FAILURE);
  if ((my_malloc_map(&bsq)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (my_split(&bsq) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  malloc_my_int_tab(&bsq);
  if (my_find_wall(&bsq) == EXIT_FAILURE)
    return (my_put_error("Error: Invalid map\n"));
  make_square(&bsq);
  my_show_wordtab(&bsq);
  my_free(&bsq);
  return (EXIT_SUCCESS);
}
