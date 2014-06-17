/*
** func3.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Thu Dec 19 19:02:37 2002 bruno legros
** Last update Sun Dec 22 18:45:44 2002 eric augustin
*/

#include "func3.h"

int	not_implemented(t_func_arg *arg)
{
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** ll rx, n
** Charge n dans le registre rx entier. Le fonctionnement est independant
** de P et n'affecte pas Z
*/
int	ll(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  int2reg(arg->proc->reg[arg->rx - 1], arg->n);
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** ld rx, [ry]
** Charge les P + 1 quartets stockes a l'adresse PC + (ry % IDX_MOD)
** dans les quartets 0 a P de rx. ry est signe et utilise en entier.
** Le fonctionnement n'affecte pas Z.
*/
int	ld(t_func_arg *arg)
{
  int	pos;

  if (!arg || !arg->proc || !arg->vm || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  if (arg->proc->wbuf->place < 0)
    arg->proc->wbuf->place = 3;
  arg->proc->reg[arg->rx - 1][arg->proc->wbuf->place / 2] &=
    ((arg->proc->wbuf->place % 2) ? 0xf0 : 0x0f);
  pos = (pc2int(arg->proc->pc) +
	 neg_mod(reg2int(arg->proc->reg[arg->ry - 1]) + 3 -
		 arg->proc->wbuf->place, IDX_MOD));
  while (pos < 0)
    pos += arg->vm->size;
  pos %= arg->vm->size;
  arg->proc->reg[arg->rx - 1][arg->proc->wbuf->place / 2] |=
    arg->vm->mem[pos / 2] & ((pos % 2) ? 0x0f : 0xf0);
  arg->proc->wbuf->place--;
  if (arg->proc->wbuf->place < 3 - arg->proc->p)
    {
      arg->proc->wbuf->place = -1;
      arg->proc->cur_work = WAIT_AFTER;
      arg->proc->rw->delay = 0;
    }
  return 0;
}

/*
** bz rx
** Effectue un saut relatif de rx modulo IDX_MOD quartets si Z = 1
** (PC = PC + (rx % IDX_MOD)). rx est signé et utilisŽé en entier.
** Le fonctionnement est indépendant de P et n'affecte pas Z.
*/
int	bz(t_func_arg *arg)
{
  int	pc;

  if (!arg || !arg->proc || !arg->vm)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  if (arg->proc->z)
    {
      pc = (pc2int(arg->proc->pc) +
	neg_mod(reg2int(arg->proc->reg[arg->rx - 1]), IDX_MOD)) %
	arg->vm->size;
      int2reg(arg->proc->pc, pc);
    }
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

int	bnz(t_func_arg *arg)
{
  int	pc;

  if (!arg || !arg->proc || !arg->vm)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  if (!arg->proc->z)
    {
      pc = (pc2int(arg->proc->pc) +
	neg_mod(reg2int(arg->proc->reg[arg->rx - 1]), IDX_MOD)) %
	arg->vm->size;
      int2reg(arg->proc->pc, pc);
    }
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

