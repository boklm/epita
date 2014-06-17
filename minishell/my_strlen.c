/*
** my_strlen.c for piscine in /u/a1/vigier_n/c/rendu/piscine/j3
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Sep 25 20:39:54 2002 nicolas vigier
** Last update Tue Nov 19 13:45:28 2002 nicolas vigier
*/

#include "my_strlen.h"

unsigned int	my_strlen(const char *str)
{
  const char	*tmp;

  tmp = str;
  while (*tmp)
    tmp++;
  return tmp - str;
}
