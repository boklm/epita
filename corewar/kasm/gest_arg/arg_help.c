/*
** arg_help.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 16:29:53 2002 olivier lecornet
** Last update Sun Dec 22 11:47:58 2002 nicolas vigier
*/

#include "gest_arg.h"

int	arg_help(int argc, char **argv, int pos, int *flag)
{
  argc = argc;
  argv = argv;
  flag = flag;
  pos = pos;
  my_write(STDOUT_FILENO, VERSION, my_strlen(VERSION));
  my_write(STDOUT_FILENO, ARG_NOT_ENOUGHT, my_strlen(ARG_NOT_ENOUGHT));
  my_write(STDOUT_FILENO, OPT, my_strlen(OPT));
  my_write(STDOUT_FILENO, OPT_NC, my_strlen(OPT_NC));
  my_write(STDOUT_FILENO, OPT_H, my_strlen(OPT_H));
  my_write(STDOUT_FILENO, OPT_V, my_strlen(OPT_V));
  my_write(STDOUT_FILENO, OPT_VERSION, my_strlen(OPT_VERSION));
  exit(0);
}
