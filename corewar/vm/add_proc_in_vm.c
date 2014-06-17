/*
** add_proc_in_vm.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 16:04:31 2002 bruno legros
** Last update Sat Dec 21 14:40:50 2002 eric augustin
*/

#include "add_proc_in_vm.h"

void		add_proc_in_vm(t_vm *vm, t_proc *proc)
{
  t_proc	*tmp, *ptmp;

  for (ptmp = NULL, tmp = vm->proc; tmp; ptmp = tmp, tmp = tmp->next) ;
  if (!ptmp)
    {
      proc->next = vm->proc;
      vm->proc = proc;
    }
  else
    {
      proc->next = ptmp->next;
      ptmp->next = proc;
    }
}

void		add_proc_tmp_in_vm(t_vm *vm, t_proc *proc)
{
  t_proc	*tmp, *ptmp;

  for (ptmp = NULL, tmp = vm->proc_tmp; tmp; ptmp = tmp, tmp = tmp->next) ;
  if (!ptmp)
  {
    proc->next = vm->proc_tmp;
    vm->proc_tmp = proc;
  }
  else
  {
    proc->next = ptmp->next;
    ptmp->next = proc;
  }
}
