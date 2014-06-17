/*
** readln.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 19:42:06 2002 nicolas vigier
** Last update Wed Dec  4 04:31:49 2002 nicolas vigier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readln.h"
#include "utils.h"

static void	*my_realloc(void *ptr, size_t oldsize, size_t newsize)
{
  void		*res;

  res = xmalloc(newsize);
  res = strncpy(res, ptr, oldsize);
  free(ptr);
  return res;
}

char	*readln(int fd, char endline)
{
  int	msize;
  int	size;
  char	*res;
  char	c;
  char	f;
  char	nul;

  nul = 0;
  res = xmalloc(msize = READLN_SIZE);
  size = 0;
  while (read(fd, &c, 1) == 1)
    {
      nul = 1;
      if (c == endline)
	break ;
      if (size >= msize - 1)
	{
	  res = my_realloc(res, msize, msize + READLN_SIZE);
	  msize += READLN_SIZE;
	}
      res[size++] = c;
    }
  if (!nul ||
      ((c == endline) && endline == '\r' &&
       (read(fd, &c, 1) != 1)))
    {
      free(res);
      return NULL;
    }
  res[size] = 0;
  return res;
}
