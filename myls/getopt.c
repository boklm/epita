/*
** getopt.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Oct 16 16:45:54 2002 nicolas vigier
** Last update Wed Oct 23 03:18:03 2002 nicolas vigier
*/

#include "myls.h"

static int	getoptblock(int flags, char *opt)
{
  while (*opt)
    {
      if (*opt == 'l')
	flags = flags | LSOPT_LONG;
      else if (*opt == 'a')
	flags = (flags | LSOPT_A) & ~LSOPT_ALL;
      else if (*opt == 'R')
	flags = flags | LSOPT_REC;
      else if (*opt == 'A')
	flags = (flags | LSOPT_ALL) & ~LSOPT_A;
      else if (*opt == 'C')
	flags = flags | LSOPT_C;
      else
	usage(1);
      opt++;
    }
  return flags;
}

int	getoptflags(int argc, char *argv[], int *place)
{
  int	res;

  res = 0;
  *place = 1;
  while (*place < argc)
    {
      if (*argv[*place] == '-')
	res = getoptblock(res, argv[*place] + 1);
      else
	return res;
      (*place)++;
    }
  return res;
}
