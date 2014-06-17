/*
** my_strcasecmp.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Dec 21 11:28:44 2002 nicolas vigier
** Last update Sat Dec 21 11:37:25 2002 nicolas vigier
*/

#include "uses_str.h"

static char	*str2lower(char *str)
{
  char		*res;
  int		size;
  int		i;

  size = my_strlen(str);
  res = xmalloc(size + 1);
  for (i = 0; i < size; i++)
    res[i] = my_tolower(str[i]);
  res[size] = 0;
  return res;
}

int	my_strcasecmp(char *str1, char *str2)
{
  int	res;
  char	*tstr1;
  char	*tstr2;

  tstr1 = str2lower(str1);
  tstr2 = str2lower(str2);
  res = my_strcmp(tstr1, tstr2);
  free(tstr1);
  free(tstr2);
  return res;
}
