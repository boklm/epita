/*
** is_num.c for corewar in /u/a1/august_e/corewar/vm/common
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:05:01 2002 eric augustin
** Last update Sun Dec 22 16:05:02 2002 eric augustin
*/
#include "is_num.h"

int	is_num(char *str)
{
  int	i;
  int	ok;

  ok = 1;
  for (i = 0; str[i]; i++)
    if (str[i] < '0' || str[i] > '9')
      ok = 0;
  return ok;
}
