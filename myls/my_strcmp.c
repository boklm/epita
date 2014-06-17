/*
** my_strcmp.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Oct 20 17:29:44 2002 nicolas vigier
** Last update Sun Oct 20 17:31:07 2002 nicolas vigier
*/

#include "myls.h"

int	my_strcmp(const char *s1, const char *s2)
{
  while (*s1 == *s2)
    {
      if (!*s1)
	return 0;
      s1++;
      s2++;
    }
  return *s1 - *s2;
}

int	my_strncmp(const char *s1, const char *s2, int n)
{
  while (n-- && (*s1 == *s2++))
      if (!*s1++)
        return 0;
  if (++n)
    return *s1 - *--s2;
  else
    return 0;
}
