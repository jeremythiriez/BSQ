/*
** my_strcpy.c for my_strcpy.c in /home/thirie_a/rendu/Piscine_C_J06/ex02
** 
** Made by jeremy thiriez
** Login   <thirie_a@epitech.net>
** 
** Started on  Mon Mar  7 09:17:44 2016 jeremy thiriez
** Last update Mon Mar  7 15:31:35 2016 jeremy thiriez
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
