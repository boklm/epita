/*
** vm_execute.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:51:49 2002 eric augustin
** Last update Sun Dec 22 15:51:51 2002 eric augustin
*/
#include "../vm.h"
#include "vm_execute.h"
#include "../write/write.h"
#include "../common/my_hexdump.h"
#include "check_fork.h"
#include "../interface/aff.h"

void	exec_main(t_vm *vm)
{
  read_in_mem(vm);
  waiting_for_nothing(vm);
  now_just_execute(vm);
  check_write(vm);
  if (vm->proc_tmp)
    check_fork(vm);
#ifdef BONUS
  if (vm->flags & BONBON)
    test_redraw(vm);
#endif
  waiting_after(vm);
  are_they_alive(vm);
  check_if_new_epoch(vm);
}

void	dump_mem(t_vm *vm)
{
  my_hexdump(vm->mem, vm->size / 2);
  exit(0);
}

void	vm_execute(t_vm *vm, char **players)
{
  int	step, dump;

  for (step = 0, dump = vm->dump; is_game_set(vm); vm->nb_cycles++)
  {
    exec_main(vm);
    if (vm->flags & STEP)
    {
      if (step > 1)
	step--;
      else
	step = step_by_step(vm);
    }
    if ((vm->flags & DUMP) && (vm->dump != -1))
    {
      if (dump > 0)
	dump--;
      else
	dump_mem(vm);
    }
  }
  the_winner_is(vm, players);
}
