/*
** arg_nc.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 16:29:20 2002 olivier lecornet
** Last update Wed Dec 11 16:29:39 2002 olivier lecornet
*/

#include "gest_arg.h"

int	arg_nc(int argc, char **argv, int pos, int *flag)
{
  *flag |= NC;
  argv = argv;
  argc = argc;
  return (pos + 1);
}
