/*
** my_strcpy.c for corewar in /u/a1/vigier_n/corewar/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Dec 20 05:41:48 2002 nicolas vigier
** Last update Fri Dec 20 05:44:40 2002 nicolas vigier
*/

#include "uses_str.h"

char	*my_strcpy(char *dst, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i++;
    }
  dst[i] = 0;
  return dst;
}
