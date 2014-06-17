/*
** getln.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec  4 11:01:29 2002 olivier lecornet
** Last update Sat Dec 21 16:43:36 2002 nicolas vigier
*/

#include "uses_str.h"

char    *my_strcat(char *s1, char *s2)
{
  char  *res;
  int   i, len1, len2;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if (!len1 && !len2)
    return (NULL);
  res = xmalloc((len1 + len2) * sizeof (char) + 1);
  for (i = 0; i < (len1 + len2); i++)
    if (i < len1)
      res[i] = s1[i];
    else
      res[i] = s2[i - len1];
  res[len1 + len2] = '\0';
 return (res);
}
