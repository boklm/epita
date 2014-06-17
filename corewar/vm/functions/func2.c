/*
** func2.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 15:29:36 2002 bruno legros
** Last update Sun Dec 22 18:40:28 2002 eric augustin
*/

#include "func2.h"

int		or(t_func_arg *arg)
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
	(arg->proc->reg[arg->rx - 1][i / 2] |
	arg->proc->reg[arg->ry - 1][i / 2]) & ((i % 2) ? 0x0f : 0xf0);
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

int		xor(t_func_arg *arg)
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
	(arg->proc->reg[arg->rx - 1][i / 2] ^
	arg->proc->reg[arg->ry - 1][i / 2]) & ((i % 2) ? 0x0f : 0xf0);
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

static void	my_store(t_func_arg *arg)
{
  int		pos;
  char		qrt;

  qrt = arg->proc->wbuf->buf[arg->proc->wbuf->place / 2];
  if (arg->proc->wbuf->place % 2)
    qrt <<= 4;
  pos = (pc2int(arg->proc->pc) +
	 neg_mod(reg2int(arg->proc->reg[arg->rx - 1]) + 3 -
		 arg->proc->wbuf->place, IDX_MOD));
  while (pos < 0)
    pos += arg->vm->size;
  pos %= arg->vm->size;
  add_write(pos, qrt, arg);
  (arg->proc->wbuf->place)--;
  if (arg->proc->wbuf->place < 3 - arg->proc->p)
    {
      arg->proc->wbuf->place = -1;
      arg->proc->cur_work = WAIT_AFTER;
      arg->proc->rw->delay = 0;
    }
}

/*
** st [rx], ry
** Stocke les quartets 0 a P de ry dans les P + 1 quartets
** stockes a l'adresse PC + (rx % IDX_MOD). rx est signe et utilise en entier.
** Le fonctionnement n'affecte pas Z.
*/
int	st(t_func_arg *arg)
{
  int	i;

  if (!arg || !arg->proc || !arg->vm || arg->proc->p > 3 ||
      arg->proc->p < 0 || !arg->proc->wbuf)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  if (arg->proc->wbuf->place < 0)
    {
      for (i = 3; 3 - i <= arg->proc->p; i--)
	{
	  arg->proc->wbuf->buf[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
	  arg->proc->wbuf->buf[i / 2] |=
	    (arg->proc->reg[arg->ry - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0));
	}
      arg->proc->wbuf->place = 3;
    }
  my_store(arg);
  return 0;
}

/*
** jmp rx
** Effectue un saut relatif long et inconditionnel de rx quartets
** (PC = PC + rx).
** rx est signe et utilise en entier. Le fonctionnement est independant de P
** et n'affecte pas Z.
*/
int		jmp(t_func_arg *arg)
{
  int		rx, neg;
  int		i;

  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  rx = reg2int(arg->proc->reg[arg->rx - 1]);
  neg = 0;
  if (rx < 0)
    {
      neg = 1;
      rx = -rx;
    }
  for (i = 0; i < rx; i++)
    if (neg)
      dec_pc(arg->proc->pc);
    else
      inc_pc(arg->proc->pc);
  arg->proc->rw->delay = 0;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

static void	fill_struct(t_proc *proc, t_func_arg *arg)
{
  int		i;

  proc->name = my_malloc(my_strlen(arg->proc->name) + 1);
  for (i = 0; i <= my_strlen(arg->proc->name); i++)
    proc->name[i] = arg->proc->name[i];
  proc->comment = my_malloc(my_strlen(arg->proc->comment) + 1);
  for (i = 0; i <= my_strlen(arg->proc->comment); i++)
    proc->comment[i] = arg->proc->comment[i];
  for (i = 0; i < 16; i++)
    proc->stack[i][0] = arg->proc->stack[i][0];
  for (i = 0; i < 16; i++)
    proc->stack[i][1] = arg->proc->stack[i][1];
  proc->stack_p = arg->proc->stack_p;
  for (i = 0; i < 3; i++)
    proc->wbuf->buf[i] = proc->rw->inst[i] = 0;
  proc->rw->cur_pos = 0;
  proc->wbuf->place = -1;
  proc->rw->size = 0;
  proc->rw->delay = 0;
  proc->cur_work = READING;
}

/*
** fork
** Cree un nouveau processeur en tout point identique a celui qui execute
** le fork a l'exception du registre Z qui vaudra 0 dans l'un et 1
** dans l'autre. Le fonctionnement est independant de P.
*/
int		my_fork(t_func_arg *arg)
{
  t_proc	*proc;
  int		i;

  if (!arg || !arg->proc || !arg->vm)
    return 2;
  if (arg->vm->proc_per_player[arg->proc->num - 1] > arg->vm->max_proc)
    return 1;
  proc = my_malloc(sizeof (t_proc));
  proc->wbuf = my_malloc(sizeof (t_wbuf));
  proc->rw = my_malloc(sizeof (t_rw));
  proc->pc[0] = arg->proc->pc[0];
  proc->pc[1] = arg->proc->pc[1];
  proc->num = arg->proc->num;
  for (i = 0; i < 16; i++)
    proc->reg[i][0] = arg->proc->reg[i][0];
  for (i = 0; i < 16; i++)
    proc->reg[i][1] = arg->proc->reg[i][1];
  proc->p = arg->proc->p;
  proc->live = 0;
  proc->z = arg->proc->z ? 0 : 1;
  fill_struct(proc, arg);
  add_proc_tmp_in_vm(arg->vm, proc);
  arg->proc->rw->delay = 0;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}
