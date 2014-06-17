/*
** my_hexdump.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Mon Sep 30 19:56:31 2002 bruno legros
** Last update Thu Dec 19 13:10:02 2002 bruno legros
*/

#include "my_hexdump.h"

static void    my_printchar(char c)
{
  write(1, &c, 1);
}

static void	my_printnstr(char *str, unsigned int size)
{
  unsigned int	i;

  for (i = 0; i < size; i++)
    if (str[i] >= ' ' && str[i] <= '~')
      my_printchar(str[i]);
    else
      my_printchar('.');
}

static char	*int_to_hex(char *hex, unsigned int i, int taille)
{
  int		count;

  for (count = taille - 1; count > -1; --count)
    {
      if (i % 16 <= 9)
        hex[count] = i % 16 + 48;
      else
	hex[count] = i % 16 + 87;
      i /= 16;
    }
  hex[taille] = 0;
  return hex;
}

static int	process(unsigned int count,
			unsigned int size,
			unsigned int *nb,
			char *str)
{
  char		hex[9];

  if (!(count % 16))
    {
      if (count > size)
	my_printchar(' ');
      my_printnstr("  |", 3);
      my_printnstr(str + *nb, (count > size) ? (size % 16) : 16);
      my_printchar('|');
      my_printchar('\n');
      if (count >= size)
	return 0;
      *nb += 16;
      my_printnstr(int_to_hex(hex, *nb * 2, 8), 8);
      my_printnstr("  ", 2);
    }
  else
    {
      if (count != size)
	my_printchar(' ');
      if (!(count % 8))
	my_printchar(' ');
    }
  return 1;
}

void		my_hexdump(void *data, unsigned int size)
{
  char		*str;
  char		hex[9];
  unsigned int	count, nb;

  my_printnstr(int_to_hex(hex, 0, 8), 8);
  my_printnstr("  ", 2);
  str = data;
  nb = 0;
  for (count = 1; 1; count++)
    {
      if (count <= size)
	my_printnstr(int_to_hex(hex, *(str + count - 1), 2), 2);
      else
	my_printnstr("  ", 2);
      if (!process(count, size, &nb, str))
	break ;
    }
}
