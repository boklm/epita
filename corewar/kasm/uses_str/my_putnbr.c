/*
** my_putnbr.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 12:56:15 2002 nicolas vigier
** Last update Sun Dec 22 12:57:33 2002 nicolas vigier
*/

#include "uses_str.h"

void		my_putnbr(int nbr)
{
  unsigned int	next;
  unsigned int	n;

  if (nbr < 0)
    {
      my_putchar('-');
      n = -nbr;
    }
  else
    n = nbr;
  next = n / 10;
  if (next)
    my_putnbr(next);
  my_putchar('0' + (n % 10));
}
