/*
** my_strndup.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 19:14:31 2002 nicolas vigier
** Last update Mon Nov 18 19:16:33 2002 nicolas vigier
*/

#include <stdlib.h>
#include "minishell.h"

char	*my_strndup(const char *src, int n)
{
  char	*res;

  res = malloc(n + 1);
  res[n] = NULL;
  while (n--)
    res[n] = src[n];
  return res;
}
