/*
** my_isdigit.c for corewar in /u/a1/vigier_n/corewar/kasm/uses_str
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Dec 21 11:17:52 2002 nicolas vigier
** Last update Sat Dec 21 13:17:31 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_isdigit(char c)
{
  return (c >= '0' && c <= '9');
}
