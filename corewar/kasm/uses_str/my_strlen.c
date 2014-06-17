/*
** getln.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec  4 11:01:29 2002 olivier lecornet
** Last update Mon Dec  9 19:04:40 2002 olivier lecornet
*/

#include "uses_str.h"

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}
