/*
** arg_verbose.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 11:48:41 2002 nicolas vigier
** Last update Sun Dec 22 12:00:06 2002 nicolas vigier
*/

#include "gest_arg.h"

int	arg_verbose(int argc, char **argv, int pos, int *flag)
{
  *flag |= VERBOSE_MODE;
  argc = argc;
  argv = argv;
  return pos + 1;
}
