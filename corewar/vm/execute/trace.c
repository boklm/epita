/*
** trace.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:50:31 2002 eric augustin
** Last update Sun Dec 22 15:50:32 2002 eric augustin
*/
#include "trace.h"
#include "tab.h"

void		trace_mode(t_vm *vm, t_proc *proc)
{
  int		i;
  t_func_arg	arg;

  arg.vm = vm;
  arg.proc = proc;
  init_arg(proc->rw->inst, &arg);
  i = get_inst_pos(proc->rw->inst[0]);
  write(STDOUT_FILENO, cmds[i].name, my_strlen(cmds[i].name));
  cmds[i].tr(&arg);
}
