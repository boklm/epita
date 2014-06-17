/*
** tolower.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Dec 21 11:26:05 2002 nicolas vigier
** Last update Sat Dec 21 11:38:30 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_tolower(int c)
{
  if (c < 'A' || c > 'Z')
    return c;
  return c + ('a' - 'A');
}
