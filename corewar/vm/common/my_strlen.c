/*
** my_strlen.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar/common
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 16:41:14 2002 bruno legros
** Last update Wed Dec 11 16:42:04 2002 bruno legros
*/

#include "my_strlen.h"

int	my_strlen(char *str)
{
  int	len;

  for (len = 0; str[len]; len++)
    ;
  return len;
}
