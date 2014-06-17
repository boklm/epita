/*
** utils.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 21:56:24 2002 nicolas vigier
** Last update Tue Dec  3 23:50:31 2002 nicolas vigier
*/

#include <stdlib.h>
#include "utils.h"
#include "error.h"

void	*xmalloc(size_t size)
{
  void	*res;

  if (!(res = malloc(size)))
    exit_perror("malloc");
  return res;
}

char	*my_itoa(int nbr)
{
  int	size;
  int	tmp;
  char  *rep;
  int   i;

  tmp = nbr;
  size = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      size++;
    }
  rep = xmalloc(size + 1);
  rep[size] = 0;
  for (i = size - 1; i >= 0; i--)
    {
      rep[i] = nbr % 10 + '0';
      nbr = nbr / 10;
    }
  return rep;
}
