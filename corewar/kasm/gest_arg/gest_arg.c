/*
** gest_arg.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec  4 07:54:15 2002 olivier lecornet
** Last update Sun Dec 22 12:12:02 2002 nicolas vigier
*/

#include "gest_arg.h"

t_arg	tab_arg[NB_ARGS] =
  {{"-nc", arg_nc},
   {"-help", arg_help},
   {"-v", arg_verbose},
   {"-version", arg_version}};

int	take_one_arg(int argc, char **argv, int pos, int *flag)
{
  int	i;

  for (i = 0; (i < NB_ARGS) &&
	 my_strcmp(argv[pos], tab_arg[i].label); i++) ;
  if (i < NB_ARGS)
    {
      pos = tab_arg[i].func(argc, argv, pos, flag);
      return (pos);
    }
  return (pos);
}

int	take_arg(int argc, char **argv, int *flag)
{
  int	pos, new_pos;

  if (argc == 1)
    {
      my_write(STDOUT_FILENO, ARG_NOT_ENOUGHT, my_strlen(ARG_NOT_ENOUGHT));
      exit(0);
    }
  pos = 0;
  new_pos = 1;
  while (new_pos != pos && new_pos < argc)
    {
      pos = new_pos;
      new_pos = take_one_arg(argc, argv, pos, flag);
    }
  return (pos);
}
