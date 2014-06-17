/*
** gest_arg.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Mon Dec  9 19:21:49 2002 olivier lecornet
** Last update Sun Dec 22 12:01:59 2002 nicolas vigier
*/

#ifndef GEST_ARG_H
# define GEST_ARG_H

# include "../asm.h"
# include "arg_nc.h"
# include "arg_help.h"
# include "arg_verbose.h"
# include "arg_version.h"

# define ARG_NOT_ENOUGHT	"asm: usage: [-help] [-v] [-version] [-nc] [file ...]\n"
# define NB_ARGS		4

# define VERSION		"Assembler Version 1.0\n"
# define OPT			"Available options :\n"
# define OPT_NC			"-nc\t\tDon't write output on disk\n"
# define OPT_H			"-help\t\tDisplay this help and exit\n"
# define OPT_V			"-v\t\tSet verbose mode\n"
# define OPT_VERSION		"-version\tDisplay version number and exit\n"

typedef struct	s_arg
{
  char		*label;
  int		(*func) (int argc, char **argv, int pos, int *flag);
}		t_arg;

int	take_arg(int argc, char **argv, int *flag);

#endif /* GEST_ARG_H */
