/*
** init2.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:48:51 2002 eric augustin
** Last update Sun Dec 22 15:48:52 2002 eric augustin
*/
#include "init_arg.h"

void	init6(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->rx = (inst[0] & 0x0f) + 1;
  arg->n = (((inst[1] & 0xf0) >> 4) & 0x0f) |
    (((inst[1] & 0x0f) << 4) & 0xf0);
}

void	init7(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->rx = (inst[0] & 0x0f) + 1;
  arg->n |= (((inst[2] & 0xf0) >> 4) & 0x0f) |
    (((inst[2] & 0x0f) << 4) & 0xf0);
  arg->n <<= 8;
  arg->n |= (((inst[1] & 0xf0) >> 4) & 0x0f) |
    (((inst[1] & 0x0f) << 4) & 0xf0);
}

void	init8(char inst[3], t_func_arg *arg)
{
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
  arg->rx = (((inst[1] & 0xf0) >> 4) & 0x0f) + 1;
}

void	init0(char inst[3], t_func_arg *arg)
{
  inst[2] = 0;
  arg->rx = 0;
  arg->ry = 0;
  arg->n = 0;
}
