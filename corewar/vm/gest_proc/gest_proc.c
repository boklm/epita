/*
** gest_proc.c for corewar in /u/a1/august_e/corewar/vm/gest_proc
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:08:35 2002 eric augustin
** Last update Sun Dec 22 16:08:37 2002 eric augustin
*/

#include "gest_proc.h"

void	free_proc(t_proc *proc)
{
  if (proc->name)
    free(proc->name);
  if (proc->comment)
    free(proc->comment);
  free(proc->rw);
  free(proc->wbuf);
  free(proc);
}

void		suppr_proc(t_vm *vm, t_proc *proc)
{
  t_proc	*ptmp, *tmp;

  if (!proc)
    return ;
  for (ptmp = NULL, tmp = vm->proc; tmp; ptmp = tmp, tmp = tmp->next)
    if (tmp == proc)
      {
	if (!ptmp)
	  vm->proc = tmp->next;
	else
	  ptmp->next = tmp->next;
	free_proc(tmp);
	break ;
      }
}

t_proc		*find_first_proc(t_proc *proc, unsigned int n)
{
  t_proc	*tmp;

  for (tmp = proc; tmp; tmp = tmp->next)
    if (tmp->num == n)
      return tmp;
  return NULL;
}

int		suppr_first_proc(t_proc *proc, unsigned int n)
{
  t_proc	*ptmp, *tmp;

  for (ptmp = NULL, tmp = proc; tmp; ptmp = tmp, tmp = tmp->next)
    if (tmp->num == n)
      {
	if (!ptmp)
	  proc = tmp->next;
	else
	  ptmp->next = tmp->next;
	free_proc(tmp);
	return 1;
      }
  return 0;
}
