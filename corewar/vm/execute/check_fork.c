/*
** check_fork.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 14:58:29 2002 eric augustin
** Last update Sun Dec 22 14:58:41 2002 eric augustin
*/
#include "../gest_proc/gest_proc.h"
#include "../add_proc_in_vm.h"

int		cannot_fork(t_vm *vm, unsigned int i)
{
  t_proc	*tmp;
  int		count;

  for (count = 0, tmp = vm->proc_tmp; tmp; tmp = tmp->next)
    if (tmp->num == i + 1)
      count++;
  if (vm->proc_per_player[i] + count > vm->max_proc)
    return 1;
  return 0;
}

void		remove_proc_from_tmp(t_vm *vm, unsigned int i)
{
  t_proc	*ptmp, *tmp;

  if (i > vm->nb_players)
    return ;
  for (ptmp = NULL, tmp = vm->proc_tmp; tmp;)
    if (tmp->num == i + 1)
    {
      if (!ptmp)
        vm->proc_tmp = tmp->next;
      else
        ptmp->next = tmp->next;
      free_proc(tmp);
      ptmp = NULL;
      tmp = vm->proc_tmp;
    }
  else
  {
    ptmp = tmp;
    tmp = tmp->next;
  }
}

void		check_fork(t_vm *vm)
{
  unsigned int	i;
  t_proc	*proc;

  for (i = 0; i < vm->nb_players; i++)
    if (cannot_fork(vm, i))
      remove_proc_from_tmp(vm, i);
  while (vm->proc_tmp)
  {
    proc = vm->proc_tmp;
    vm->proc_tmp = vm->proc_tmp->next;
    add_proc_in_vm(vm, proc);
    vm->proc_per_player[proc->num - 1]++;
  }
}
