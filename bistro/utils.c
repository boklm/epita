/*
** utils.c for bistromathique in /u/a1/legros_b/c/rendu/myls
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 16 10:43:49 2002 bruno legros
** Last update Sat Nov  9 10:42:39 2002 bruno legros
*/

#include "bistro.h"

int	my_strlen(const char *str)
{
  int	len;

  for (len = 0; str[len]; len++) ;
  return len;
}

void	my_strncpy(char *dest, char *str, int len)
{
  int	i;

  for (i = 0; i < len; i++)
    dest[i] = str[i];
}

void	my_puterror(char *str)
{
  my_putstr(str);
  exit(1);
}
