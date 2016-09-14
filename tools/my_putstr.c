/*
** my_putstr.c for my_putstr.c in /home/thirie_a/rendu/Piscine_C_J04
**
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
**
** Started on  Thu Mar  3 09:23:57 2016 jeremy thiriez
** Last update Sun May 22 13:38:37 2016 jeremy thiriez
*/

#include "bsq.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_put_color(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 'x')
	{
	  my_putstr("\033[34m");
	  my_putchar(str[i]);
	}
      else if (str[i] == 'o')
	{
	  my_putstr("\033[31m");
	  my_putchar(str[i]);
	}
      else if (str[i] == '.')
	{
	  my_putstr("\033[35m");
	  my_putchar(str[i]);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
