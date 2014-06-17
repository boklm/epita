/*
** gest_arg.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Mon Dec  9 19:21:49 2002 olivier lecornet
** Last update Sat Dec 21 19:04:11 2002 olivier lecornet
*/

#ifndef GEST_ARG_H
# define GEST_ARG_H

# include "../vm.h"
# include "../common/my_strncmp.h"
# include "../common/my_strlen.h"
# include "../common/my_atoi.h"
# include "../common/my_write.h"
# include "../error/my_error.h"

# define VERSION	"Corewar Virtual Machine v1.0\n"
# define AUTHORS1	"Make by Bruno Legros, Augustin Eric, \n"
# define AUTHORS2	"Nicolas Vigier, Olivier Lecornet\n"
# define DATE		"On 2002 December 20\n"
# define ARGNE1		"corewar [-help] [-ms n] [-mp n] [-im n] [-dump n] "
# define ARGNE2		"[-cy n] [-cd n] [-ep n] [-t] [-step]"
# define ARGNE3		"[file1 ... [file15]]\n"

#ifdef BONUS
# define NB_ARGS	11
#else
# define NB_ARGS	10
#endif


# define OPT		"\n"
# define OPT_DP		"-dump\t\tDon't write output on disk\n"
# define OPT_H		"-help\t\tDisplay the help\n"
# define OPT_MS		"-ms\t\tSpecify size of memory\n"
# define OPT_MP		"-mp\t\tSpecify max number of processors\n"
# define OPT_IM		"-im\t\tSpecify IDX_MOD constant\n"
# define OPT_CY		"-cy\t\tSpecify CYCLES_TO_DEATH constant\n"
# define OPT_CD		"-cd\t\tSpecify CYCLES_DELTA constant\n"
# define OPT_EP		"-ep\t\tSpecify EPOCH constant\n"
# define OPT_STEP	"-step\t\tExecution step by step\n"
# define OPT_TRACE	"-t\t\tTracing executed functions\n"

typedef struct	s_arg
{
  char		*label;
  int		size;
  int		(*func)(int argc, char **argv, int pos, t_vm *vm);
}		t_arg;

int		take_arg(int argc, char **argv, t_vm *vm);

#endif /* !GEST_ARG_H */
