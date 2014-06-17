/*
** init1.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:48:38 2002 eric augustin
** Last update Sun Dec 22 15:48:40 2002 eric augustin
*/
#include "init_arg.h"

void	init1(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->n = inst[0] & 0x0f;
}

void	init2(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->ry = (inst[1] & 0x0f) + 1;
  arg->rx = (((inst[1] & 0xf0) >> 4) & 0x0f) + 1;
}

void	init3(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->n = inst[1] & 0x0f;
  arg->rx = (((inst[1] & 0xf0) >> 4) & 0x0f) + 1;
}

void	init4(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->rx = (inst[0] & 0x0f) + 1;
}

void	init5(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->rx = (inst[0] & 0x0f) + 1;
  arg->ry = (((inst[1] & 0xf0) >> 4) & 0x0f) + 1;
}
