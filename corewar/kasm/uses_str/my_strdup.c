/*
** my_strcpy.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Mon Dec  9 15:21:09 2002 olivier lecornet
** Last update Fri Dec 20 05:36:07 2002 nicolas vigier
*/

#include "uses_str.h"

char	*my_strdup(char *src)
{
  int	i, len;
  char	*dest;

  len = my_strlen(src);
  dest = xmalloc(len * sizeof (char) + 1);
  for (i = 0; i < len; i++)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
