/*
** my_strncpy.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Tue Dec 10 15:55:49 2002 olivier lecornet
** Last update Tue Dec 10 15:58:14 2002 olivier lecornet
*/

#include "uses_str.h"

char	*my_strncpy(char *src, int n)
{
  char	*res;
  int	i;

  res = xmalloc(sizeof (char) * n + 1);
  for (i = 0; i < n; i++)
    res[i] = src[i];
  res[i] = 0;
  return (res);
}
