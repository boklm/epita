/*
** init_arg.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:49:09 2002 eric augustin
** Last update Sun Dec 22 15:49:18 2002 eric augustin
*/
#include "tab.h"
#include "vm_execute.h"

void    init_arg(char inst[3], t_func_arg *arg)
{
  int	i;

  i = get_inst_pos(inst[0]);
  cmds[i].set_arg(inst, arg);
}
