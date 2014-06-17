/*
** gest_arg.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec  4 07:54:15 2002 olivier lecornet
** Last update Sat Dec 21 19:36:44 2002 olivier lecornet
*/

#include "gest_arg.h"
#include "../common/is_num.h"

static int	arg_ms(int argc, char **argv, int pos, t_vm *vm);
static int	arg_dump(int argc, char **argv, int pos, t_vm *vm);
static int	arg_help(int argc, char **argv, int pos, t_vm *vm);
static int	arg_mp(int argc, char **argv, int pos, t_vm *vm);
static int	arg_im(int argc, char **argv, int pos, t_vm *vm);
static int	arg_cy(int argc, char **argv, int pos, t_vm *vm);
static int	arg_cd(int argc, char **argv, int pos, t_vm *vm);
static int	arg_ep(int argc, char **argv, int pos, t_vm *vm);
static int	arg_step(int argc, char **argv, int pos, t_vm *vm);
static int	arg_tr(int argc, char **argv, int pos, t_vm *vm);
static int	arg_bonus(int argc, char **argv, int pos, t_vm *vm);

static t_arg	tab_arg[11] =
  {
    {"-dump", 5, arg_dump},
    {"-help", 5, arg_help},
    {"-ms", 3, arg_ms},
    {"-im", 3, arg_im},
    {"-cy", 3, arg_cy},
    {"-cd", 3, arg_cd},
    {"-ep", 3, arg_ep},
    {"-mp", 3, arg_mp},
    {"-step", 5, arg_step},
    {"-t", 2, arg_tr},
    {"-bonus", 6, arg_bonus}
  };

static int	arg_im(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->idx_mod = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_cy(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->c_to_d = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_cd(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->delta = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_ep(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->epoch = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_mp(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->max_proc = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_ms(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->size = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_dump(int argc, char **argv, int pos, t_vm *vm)
{
  vm->flags |= DUMP;
  argc = argc;
  if (pos + 1 >= argc || !is_num(argv[pos + 1]))
    my_error(ARGNE1, ARGNE2, ARGNE3, 1);
  vm->dump = my_atoi(argv[pos + 1]);
  return (pos + 2);
}

static int	arg_step(int argc, char **argv, int pos, t_vm *vm)
{
  vm->flags |= STEP;
  argv = argv;
  argc = argc;
  return (pos + 1);
}

static int	arg_bonus(int argc, char **argv, int pos, t_vm *vm)
{
  vm->flags |= BONBON;
  argv = argv;
  argc = argc;
  return (pos + 1);
}

static int      arg_tr(int argc, char **argv, int pos, t_vm *vm)
{
  vm->flags |= TRACE;
  argv = argv;
  argc = argc;
  return (pos + 1);
}

static int	arg_help(int argc, char **argv, int pos, t_vm *vm)
{
  argc = argc;
  argv = argv;
  vm = vm;
  pos = pos;
  my_write(STDOUT_FILENO, VERSION, my_strlen(VERSION));
  my_write(STDOUT_FILENO, AUTHORS1, my_strlen(AUTHORS1));
  my_write(STDOUT_FILENO, AUTHORS2, my_strlen(AUTHORS2));
  my_write(STDOUT_FILENO, DATE, my_strlen(DATE));
  my_write(STDOUT_FILENO, ARGNE1, my_strlen(ARGNE1));
  my_write(STDOUT_FILENO, ARGNE2, my_strlen(ARGNE2));
  my_write(STDOUT_FILENO, ARGNE3, my_strlen(ARGNE3));
  my_write(STDOUT_FILENO, OPT, my_strlen(OPT));
  my_write(STDOUT_FILENO, OPT_DP, my_strlen(OPT_DP));
  my_write(STDOUT_FILENO, OPT_H, my_strlen(OPT_H));
  my_write(STDOUT_FILENO, OPT_MS, my_strlen(OPT_MS));
  my_write(STDOUT_FILENO, OPT_MP, my_strlen(OPT_MP));
  my_write(STDOUT_FILENO, OPT_IM, my_strlen(OPT_IM));
  my_write(STDOUT_FILENO, OPT_CY, my_strlen(OPT_CY));
  my_write(STDOUT_FILENO, OPT_CD, my_strlen(OPT_CD));
  my_write(STDOUT_FILENO, OPT_EP, my_strlen(OPT_EP));
  my_write(STDOUT_FILENO, OPT_STEP, my_strlen(OPT_STEP));
  my_write(STDOUT_FILENO, OPT_TRACE, my_strlen(OPT_TRACE));
  exit(0);
}

static int	take_one_arg(int argc, char **argv, int pos, t_vm *vm)
{
  int	i;

  for (i = 0; (i < NB_ARGS) &&
	 my_strncmp(argv[pos], tab_arg[i].label, tab_arg[i].size); i++) ;
  if (i < NB_ARGS)
    pos = tab_arg[i].func(argc, argv, pos, vm);
  return pos;
}

int	take_arg(int argc, char **argv, t_vm *vm)
{
  int	pos, new_pos;

  vm->flags = 0;
  if (argc == 1)
    my_error(ARGNE1, ARGNE2, ARGNE3, 2);
  pos = 0;
  new_pos = 1;
  while (new_pos != pos && new_pos < argc)
    {
      pos = new_pos;
      new_pos = take_one_arg(argc, argv, pos, vm);
    }
  return new_pos;
}
