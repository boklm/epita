/*
** strutils.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 22:50:16 2002 nicolas vigier
** Last update Tue Dec  3 08:57:42 2002 nicolas vigier
*/

#include "strutils.h"

char	*remove_lspace(char *str)
{
  while (*str && (*str == ' '))
    str++;
  return str;
}

char	*remove_rspace(char *str)
{
  int	i;

  i = strlen(str);
  while (i >= 0 && str[i] == ' ')
    str[i--] = 0;
  return str;
}
