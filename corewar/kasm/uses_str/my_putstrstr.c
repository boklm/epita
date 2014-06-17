/*
** my_putstrstr.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 12:59:41 2002 nicolas vigier
** Last update Sun Dec 22 13:02:17 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_putstrstr(char *str, char *s)
{
  while (*str)
    {
      if (*str == '^')
	my_putstr(s);
      else
	my_write(STDOUT_FILENO, str, 1);
      str++;
    }
  return 1;
}
