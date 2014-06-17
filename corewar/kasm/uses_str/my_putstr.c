/*
** my_putstr.c for corewar in /u/a1/vigier_n/corewar/kasm/uses_str
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 12:35:23 2002 nicolas vigier
** Last update Sun Dec 22 12:36:39 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_putstr(char *str)
{
  return my_write(STDOUT_FILENO, str, my_strlen(str));
}
