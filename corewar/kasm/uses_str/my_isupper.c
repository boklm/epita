/*
** my_isupper.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 12:21:43 2002 nicolas vigier
** Last update Sun Dec 22 12:22:33 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_isupper(char c)
{
  return (c >= 'A' && c <= 'Z');
}
