/*
** invert_quartet.c for corewar in /u/a1/vigier_n/corewar/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Dec 20 11:04:01 2002 nicolas vigier
** Last update Fri Dec 20 11:05:10 2002 nicolas vigier
*/

#include "../asm.h"

char		invert_quartet(char elt)
{
  char		res;
  int		i;

  res = 0;
  for (i = 0; i < 4; i++)
    {
      res <<= 1;
      res = res | (elt & 1);
      elt >>= 1;
    }
  return res;
}
