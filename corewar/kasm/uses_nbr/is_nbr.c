/*
** is_nbr.c for corewar in /u/a1/vigier_n/asm_new/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Dec 12 18:53:19 2002 nicolas vigier
** Last update Thu Dec 12 18:55:03 2002 nicolas vigier
*/

#include "uses_nbr.h"

int	is_nbr(char c)
{
  return (c > '0' && c < '9');
}
