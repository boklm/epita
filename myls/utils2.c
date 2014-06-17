/*
** utils2.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Oct 20 19:00:57 2002 nicolas vigier
** Last update Tue Oct 22 20:16:09 2002 nicolas vigier
*/

#include "myls.h"

char	*my_strcpy(char *dest, const char *src)
{
  char	c;
  char	*res;

  res = dest;
  while ((c = *src++))
    *dest++ = c;
  *dest = 0;
  return res;
}

char	*my_strcat(char *dest, const char *src)
{
  char	*res;

  res = dest;
  while (*dest++)
    ;
  my_strcpy(--dest, src);
  return res;
}

char	*my_strdup(char *str)
{
  char	*res;
  char	*res_save;

  res_save = res = malloc(strlen(str) + 1);
  while ((*res++ = *str++))
    ;
  return res_save;
}
