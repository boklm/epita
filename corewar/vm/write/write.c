/*
** write.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 17:58:57 2002 bruno legros
** Last update Sun Dec 22 18:41:27 2002 eric augustin
*/

#include "write.h"
#include "../interface/aff.h"

static void	add_qrt(t_write *vmwrite, char qrt, t_func_arg *arg)
{
  t_qrt		*new;

  if (!vmwrite || !arg || !arg->proc)
    return ;
  new = my_malloc(sizeof (t_qrt));
  new->qrt = qrt;
  new->num = arg->proc->num;
  new->next = vmwrite->qrt;
  vmwrite->qrt = new;
}

/*
** [qrt] contains the quartet to write at position [addr] in the mem
** the quartet to write is in the first quartet of [qrt]
*/
int		add_write(unsigned int addr, char qrt, t_func_arg *arg)
{
  t_write	*tmp, *new;

  if (!arg || !arg->vm)
    return 1;
  for (tmp = arg->vm->vmwrite; tmp; tmp = tmp->next)
    if (tmp->addr == addr)
      {
	add_qrt(tmp, qrt, arg);
	return 0;
      }
  new = my_malloc(sizeof (t_write));
  new->addr = addr;
  new->qrt = NULL;
  add_qrt(new, qrt, arg);
  new->next = arg->vm->vmwrite;
  arg->vm->vmwrite = new;
  return 0;
}

static void	free_all_qrt(t_qrt *qrt)
{
  if (qrt)
    {
      free_all_qrt(qrt->next);
      free(qrt);
    }
}

static void	free_all_write(t_write *vmwrite)
{
  if (vmwrite)
    {
      free_all_write(vmwrite->next);
      free_all_qrt(vmwrite->qrt);
      free(vmwrite);
    }
}

void		check_write(t_vm *vm)
{
  t_write	*vmwrite;
  t_qrt		*qrt;
  int		i;

  if (!vm)
    return ;
  for (vmwrite = vm->vmwrite; vmwrite; vmwrite = vmwrite->next)
    {
      for (i = 0, qrt = vmwrite->qrt; qrt; qrt = qrt->next, i++) ;
      if (i == 1)
	{
	  vm->mem[vmwrite->addr / 2] &= ((vmwrite->addr % 2) ? 0xf0 : 0x0f);
	  if (vmwrite->addr % 2)
	    vmwrite->qrt->qrt >>= 4;
	  vm->mem[vmwrite->addr / 2] |= vmwrite->qrt->qrt &
	    ((vmwrite->addr % 2) ? 0x0f : 0xf0);
#ifdef BONUS
	  if (vm->flags & BONBON)
	    actual_player_table(vm, vmwrite->qrt->num,
				vmwrite->addr, vm->env->mem);
#endif
	}
    }
  free_all_write(vm->vmwrite);
  vm->vmwrite = NULL;
}
