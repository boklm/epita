/*
** vm_func.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:53:46 2002 eric augustin
** Last update Sun Dec 22 18:43:00 2002 eric augustin
*/
#include "../vm.h"
#include "vm_execute.h"
#include "tab.h"
#include "trace.h"
#include "../gest_proc/gest_proc.h"

static void	read_mem_value(t_vm *vm, t_proc *proc)
{
  int		pc;

  pc = pc2int(proc->pc) % vm->size;
  if ((pc % 2) == (proc->rw->cur_pos % 2))
    proc->rw->inst[proc->rw->cur_pos / 2] |=
      proc->rw->cur_pos % 2 ?
      vm->mem[pc / 2] & 0x0f :
      vm->mem[pc / 2] & 0xf0;
  else
    proc->rw->inst[proc->rw->cur_pos / 2] |=
      proc->rw->cur_pos % 2 ?
      (vm->mem[pc / 2] & 0xf0) >> 4 :
      (vm->mem[pc / 2] & 0x0f) << 4;
}

void		read_in_mem(t_vm *vm)
{
  t_proc	*proc;

  for (proc = vm->proc; proc; proc = proc->next)
    if (proc->cur_work == READING)
    {
      if (!proc->rw->size || (proc->rw->cur_pos < proc->rw->size))
      {
	read_mem_value(vm, proc);
	inc_pc(proc->pc);
	proc->rw->cur_pos++;
      }
      if (!(proc->rw->cur_pos < 2) && !proc->rw->size)
      {
        proc->rw->size = get_inst_size(proc->rw->inst);
        proc->rw->delay = get_inst_delay(proc->rw->inst) + 1;
      }
      if (proc->rw->size && proc->rw->cur_pos >= proc->rw->size)
      {
        proc->cur_work = WAITING;
	if (vm->flags & TRACE)
	  trace_mode(vm, proc);
      }
    }
}

void		waiting_for_nothing(t_vm *vm)
{
  t_proc	*proc;

  for (proc = vm->proc; proc; proc = proc->next)
    if (proc->cur_work == WAITING)
    {
      if (proc->rw->delay)
        proc->rw->delay--;
      else
        proc->cur_work = EXECUTE;
    }
}

void		waiting_after(t_vm *vm)
{
  t_proc	*proc;

  for (proc = vm->proc; proc; proc = proc->next)
    if (proc->cur_work == WAIT_AFTER)
    {
      if (proc->rw->delay)
        proc->rw->delay--;
      else
      {
	proc->rw->inst[0] = proc->rw->inst[1] = proc->rw->inst[2] = 0;
	proc->rw->cur_pos = 0;
	proc->rw->delay = 0;
	proc->rw->size = 0;
        proc->cur_work = READING;
      }
    }
}

void		now_just_execute(t_vm *vm)
{
  t_proc	*proc, *next;
  t_func_arg	arg;
  int		i;
  int		res;

  for (next = proc = vm->proc; proc; proc = next)
    {
      next = proc->next;
      if (proc->cur_work == EXECUTE)
	{
	  arg.vm = vm;
	  arg.proc = proc;
	  init_arg(proc->rw->inst, &arg);
	  i = get_inst_pos(proc->rw->inst[0]);
	  res = cmds[i].func(&arg);
	  if (res)
	  {
	    proc->rw->delay = 0;
	    proc->cur_work = WAIT_AFTER;
	  }
	}
    }
}

void		are_they_alive(t_vm *vm)
{
  t_proc	*proc;
  t_proc	*tmp;

  for (proc = vm->proc; proc; proc = proc)
  {
    if (proc->live < vm->c_to_d)
    {
      proc->live++;
      proc = proc->next;
    }
    else
    {
      tmp = proc;
      proc = proc->next;
      vm->proc_per_player[tmp->num - 1]--;
      suppr_proc(vm, tmp);
    }
  }
}
