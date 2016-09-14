/*
** my_split.c for my_split.c in /home/thirie_a/tech_1/C_Prog_Elem/CPE_2015_BSQ
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Apr 25 18:30:09 2016 jeremy thiriez
** Last update Sun May 22 14:35:09 2016 jeremy thiriez
*/

#include "bsq.h"

void	my_count_col_and_line(t_bsq *bsq)
{
  int	i;

  i = 0;
  if (bsq->buff[i] != '.' && bsq->buff[i] != 'o')
    {
      while (bsq->buff[i] != '\n' && bsq->buff[i])
	{
	  ++bsq->count_first_line;
	  ++i;
	}
      ++bsq->count_first_line;
      ++i;
    }
  while (bsq->buff[i] != '\n' && bsq->buff[i])
    {
      bsq->size_col += 1;
      i += 1;
    }
  while (bsq->buff[i])
    {
      if (bsq->buff[i] == '\n' || bsq->buff[i] == 0)
	bsq->size_line += 1;
      i += 1;
    }
}

int	my_malloc_map(t_bsq *bsq)
{
  int	i;

  i = 0;
  my_count_col_and_line(bsq);
  if ((bsq->map = malloc(sizeof(char *) * (bsq->size_line + 1))) == NULL)
    return (EXIT_FAILURE);
  while (i < bsq->size_line)
    {
      if ((bsq->map[i] =
	   malloc(sizeof(char) * (bsq->size_col + 1))) == NULL)
	return (EXIT_FAILURE);
      ++i;
    }
  return (EXIT_SUCCESS);
}

char		*read_map(char **av, t_bsq *bsq)
{
  int		fd;
  struct stat	st;

  if (stat(av[1], &st) == EXIT_FAILURE)
    return (NULL);
  if ((bsq->buff = malloc(sizeof(char) * (st.st_size + 1))) == NULL)
    return (NULL);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (NULL);
  if ((bsq->ret = read(fd, bsq->buff, st.st_size)) == 0)
    return (NULL);
  else
    bsq->buff[bsq->ret] = 0;
  if (bsq->buff[bsq->ret - 1] != '\n')
    {
      my_put_error("Error: Invalid map\n");
      return (NULL);
    }
  return (bsq->buff);
}

int	my_split(t_bsq *bsq)
{
  int	i;
  int	j;
  int	k;

  i = bsq->count_first_line;
  j = 0;
  while (bsq->buff[i])
    {
      k = 0;
      while (k < bsq->size_col)
	{
	  bsq->map[j][k] = bsq->buff[i];
	  ++i;
	  ++k;
	}
      if (bsq->buff[i] != '\n')
	return (my_put_error("Error: Invalid map\n"));
      bsq->map[j][k] = 0;
      ++j;
      ++i;
    }
  bsq->map[j] = 0;
  return (EXIT_SUCCESS);
}
