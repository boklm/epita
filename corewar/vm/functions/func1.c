/*
** func1.c for corewar in /u/a1/august_e/corewar/vm/functions
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:07:13 2002 eric augustin
** Last update Sun Dec 22 16:07:15 2002 eric augustin
*/
#include "func1.h"

static int	die(t_func_arg *arg)
{
  if (!arg || !arg->proc || !arg->vm)
    return 2;
  arg->vm->proc_per_player[arg->proc->num - 1]--;
  suppr_proc(arg->vm, arg->proc);
  return 0;
}

int	live_or_die(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (!arg->n)
    return die(arg);
  if (arg->n > arg->vm->nb_players)
    {
      arg->proc->cur_work = WAIT_AFTER;
      arg->proc->rw->delay = 0;
      return 1;
    }
  arg->vm->last_live[arg->n] = 1;
  arg->vm->lives_per_cycle++;
  arg->proc->live = 0;
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

int	mov(t_func_arg *arg)
{
  int	i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  for (i = 3; 3 - i <= arg->proc->p; i--)
    {
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	(arg->proc->reg[arg->ry - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0));
    }
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

int		swp(t_func_arg *arg)
{
  unsigned char	tmp_reg[2];
  int		i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  for (i = 3; 3 - i <= arg->proc->p; i--)
    {
      tmp_reg[i / 2] &= (i % 2 ? 0xf0 : 0x0f);
      tmp_reg[i / 2] |=
	(arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0));
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	(arg->proc->reg[arg->ry - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0));
      arg->proc->reg[arg->ry - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->ry - 1][i / 2] |=
	(tmp_reg[i / 2] & ((i % 2) ? 0x0f : 0xf0));
    }
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

int	not(t_func_arg *arg)
{
  int	i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  arg->proc->z = 1;
  for (i = 3; 3 - i <= arg->proc->p; i--)
    {
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	(~(arg->proc->reg[arg->ry - 1][i / 2]) & ((i % 2) ? 0x0f : 0xf0));
      if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
	arg->proc->z = 0;
    }
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

int		and(t_func_arg *arg)
{
  int		i;
  unsigned char	tmp_reg[2];

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  arg->proc->z = 1;
  for (i = 3; 3 - i <= arg->proc->p; i--)
    {
      tmp_reg[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      tmp_reg[i / 2] |=
	arg->proc->reg[arg->rx - 1][i / 2] &
	arg->proc->reg[arg->ry - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0);
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	tmp_reg[i / 2] & ((i % 2) ? 0x0f : 0xf0);
      if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
	arg->proc->z = 0;
    }
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}
