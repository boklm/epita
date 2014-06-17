/*
** my_putnbr.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Oct 21 22:59:54 2002 nicolas vigier
** Last update Mon Oct 21 23:00:05 2002 nicolas vigier
*/

#include "myls.h"

void    	my_putnbr(int nbr)
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

void	my_putnbr_alignl(int nbr, int size)
{
  int	tmp;
  int	len;

  tmp = nbr;
  len = 1;
  while ((tmp = tmp / 10))
    len++;
  my_putnbr(nbr);
  while (len++ < size)
    my_putchar(' ');
}

void	my_putnbr_alignr(int nbr, int size)
{
  int	tmp;
  int	len;

  tmp = nbr;
  len = 1;
  while ((tmp = tmp / 10))
    len++;
  while (len++ < size)
    my_putchar(' ');
  my_putnbr(nbr);
}
