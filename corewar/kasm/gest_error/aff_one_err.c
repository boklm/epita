/*
** aff_one_err.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 14:37:43 2002 olivier lecornet
** Last update Thu Dec 12 12:42:21 2002 olivier lecornet
*/

#include "gest_errors.h"

char    *my_itoa_base(int nbr, char *base, int base_size)
{
  int   i, j;
  char  tmp[30], *res;

  if (nbr == 0)
    {
      res = xmalloc(sizeof (char) * 2);
      res[0] = '0';
      res[1] = 0;
      return (res);
    }
  for (i = 0; nbr > 0; i++)
    {
      tmp[i] = base[nbr % base_size];
      nbr /= base_size;
    }
  res = xmalloc(sizeof (char) * i);
  res[i] = '\0';
  for (j = 0; j < i; j++)
    res[j] = tmp[i - 1 - j];
  return (res);
}

void	aff_one_error(t_error *p, char *pref, char *med, char *suf)
{
  char	*line;

  line = my_itoa_base(p->line, "0123456789", 10);
  if (pref)
    my_write(STDOUT_FILENO, pref, my_strlen(pref));
  my_write(STDOUT_FILENO, line, my_strlen(line));
  if (med)
    my_write(STDOUT_FILENO, med, my_strlen(med));
  my_write(STDOUT_FILENO, p->msg, my_strlen(p->msg));
  if (suf)
    my_write(STDOUT_FILENO, suf, my_strlen(suf));
}
