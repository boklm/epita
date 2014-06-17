/*
** my_putstrnbr.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 13:04:58 2002 nicolas vigier
** Last update Sun Dec 22 13:05:32 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_putstrnbr(char *str, int nbr)
{
  while (*str)
    {
      if (*str == '^')
	my_putnbr(nbr);
      else
	my_write(STDOUT_FILENO, str, 1);
      str++;
    }
  return 1;
}
