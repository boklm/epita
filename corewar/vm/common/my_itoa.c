/*
** my_itoa.c for corewar in /u/a1/august_e/corewar/vm/common
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:03:05 2002 eric augustin
** Last update Sun Dec 22 16:03:11 2002 eric augustin
*/
#include <stdlib.h>
#include "my_strlen.h"
#include "../error/my_error.h"

char    *my_itoa(unsigned int it)
{
  char  res[30];
  char  *real_res;
  int   i;

  if (!it)
  {
    real_res = my_malloc(2 * sizeof (char));
    real_res[0] = '0';
    real_res[1] = 0;
  }
  else
  {
    for (i = 0; it; i++, it /= 10)
      res[i] = 48 + it % 10;
    res[i] = 0;
    real_res = my_malloc(my_strlen(res) + 1);
    for (i = 0; res[i]; i++)
      real_res[my_strlen(res) - i - 1] = res[i];
    real_res[my_strlen(res)] = 0;
  }
  return real_res;
}
