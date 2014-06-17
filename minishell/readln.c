/*
** readln.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 19:42:06 2002 nicolas vigier
** Last update Mon Nov 18 20:44:20 2002 nicolas vigier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"

static void	*my_realloc(void *ptr, size_t oldsize, size_t newsize)
{
  void		*res;

  res = mmalloc(newsize);
  res = my_strncpy(res, ptr, oldsize);
  free(ptr);
  return res;
}

char	*readln(void)
{
  int	msize;
  int	size;
  char	*res;
  char	c;

  res = mmalloc(msize = READLN_SIZE);
  size = 0;
  while (read(STDIN_FILENO, &c, 1) == 1)
    {
      if (c == '\n')
	break ;
      if (size >= msize - 1)
	{
	  res = my_realloc(res, msize, msize + READLN_SIZE);
	  msize += READLN_SIZE;
	}
      res[size++] = c;
    }
  res[size] = 0;
  return res;
}
