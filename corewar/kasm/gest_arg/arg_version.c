/*
** arg_version.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec 22 11:53:20 2002 nicolas vigier
** Last update Sun Dec 22 11:59:09 2002 nicolas vigier
*/

#include "gest_arg.h"

int	arg_version(int argc, char **argv, int pos, int *flag)
{
  argc = argc;
  argv = argv;
  pos = pos;
  flag = flag;
  my_write(STDOUT_FILENO, VERSION, my_strlen(VERSION));
  exit(0);
}
