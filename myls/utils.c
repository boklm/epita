/*
** utils.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Oct 18 14:16:48 2002 nicolas vigier
** Last update Wed Oct 23 04:43:47 2002 nicolas vigier
*/

#include "myls.h"

unsigned int	my_strlen(const char *str)
{
  const char	*tmp;

  tmp = str;
  while (*tmp)
    tmp++;
  return tmp - str;
}

char	*concatpath(const char *rep, const char *fname)
{
  char	*res;

  res = malloc(my_strlen(rep) + my_strlen(fname) + 2);
  res = my_strcpy(res, rep);
  if (*rep)
    res = my_strcat(res, "/");
  res = my_strcat(res, fname);
  return res;
}

int	my_atoi(const char *str)
{
  int   res;
  int   s;

  res = 0;
  s = 1;
  while (*str == '-')
    {
      s = -s;
      str++;
    }
  while (*str != '\0')
    {
      res *= 10;
      res += (*str - '0');
      str++;
    }
  return s * res;
}
