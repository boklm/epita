/*
** my_putstr.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Oct 21 15:13:26 2002 nicolas vigier
** Last update Mon Oct 21 23:01:04 2002 nicolas vigier
*/

#include <unistd.h>
#include <limits.h>
#include "myls.h"

void	my_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	my_putstr(const char *str)
{
  while (*str != '\0')
    my_putchar(*str++);
}

void		my_putstr_alignl(const char *str, int size)
{
  int		len;

  len = my_strlen(str);
  my_putstr(str);
  while (len++ < size)
    my_putchar(' ');
}

void		my_putstr_alignr(const char *str, int size)
{
  int		len;

  len = my_strlen(str);
  while (len++ < size)
    my_putchar(' ');
  my_putstr(str);
}
