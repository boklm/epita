/*
** my_strncpy.c for piscine in /u/a1/vigier_n/c/rendu/piscine/j3
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Sep 25 20:42:38 2002 nicolas vigier
** Last update Mon Nov 18 19:52:17 2002 nicolas vigier
*/

#include "minishell.h"

char	*my_strncpy(char *dest, const char *src, int n)
{
  char *res;

  res = dest;
  while (*src && n--)
    *dest++ = *src++;
  while (n-- > 0)
    *dest++ = 0;
  return res;
}
