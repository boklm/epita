/*
** my_putchar.c for corewar in /u/a1/vigier_n/corewar/kasm/uses_str
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 13:07:53 2002 nicolas vigier
** Last update Sun Dec 22 13:08:31 2002 nicolas vigier
*/

#include "uses_str.h"

int	my_putchar(char c)
{
  return my_write(STDOUT_FILENO, &c, 1);
}
