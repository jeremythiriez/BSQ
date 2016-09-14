/*
** my_strcmp.c for my_strcmp.c in /home/thirie_a/rendu/Piscine_C_J06/ex06
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Mon Mar  7 11:06:53 2016 jeremy thiriez
** Last update Sun May 22 14:16:25 2016 jeremy thiriez
*/

#include "bsq.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL)
    return (2);
  while (s1[i] || s2[i])
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
