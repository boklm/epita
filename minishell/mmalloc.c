/*
** mmalloc.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 19:35:46 2002 nicolas vigier
** Last update Mon Nov 18 20:22:18 2002 nicolas vigier
*/

#include <stdlib.h>
#include "minishell.h"

void	*mmalloc(size_t size)
{
  void	*res;

  if (!(res = malloc(size)))
    error_msg(ERR_MALLOC);
  return res;
}
