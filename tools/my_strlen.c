/*
** my_strlen.c for my_strlen.c in /home/thirie_a/rendu/Piscine_C_J04
** 
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
** 
** Started on  Thu Mar  3 09:27:55 2016 jeremy thiriez
** Last update Thu Mar  3 09:29:39 2016 jeremy thiriez
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}
