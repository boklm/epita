/*
** func6.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 19:35:57 2002 bruno legros
** Last update Fri Dec 20 20:25:26 2002 bruno legros
*/

#include "func6.h"

static void	get_rx(t_func_arg *arg, int *rx)
{
  int		i;
  unsigned char	tmp;

  for (*rx = 0, i = 3 - arg->proc->p; i < 4; i++)
    {
      *rx *= 16;
      tmp = arg->proc->reg[arg->rx - 1][i / 2];
      if (!(i % 2))
	tmp >>= 4;
      tmp &= 0x0f;
      *rx += tmp;
    }
}

/*
** rx = ry - rx
*/
int		rsb(t_func_arg *arg)
{
  int		i, rx;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  arg->proc->z = 1;
  get_rx(arg, &rx);
  for (i = 3 - arg->proc->p; i < 4; i++)
    {
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	(arg->proc->reg[arg->ry - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0));
    }
  for (i = 0; i < rx; i++)
    dec_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

/*
** inc rx, n
** Incremente de n les quartets 0 a P de rx (rx = rx + n).
*/
int		inc(t_func_arg *arg)
{
  int		i;
  unsigned int	j;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  for (j = 0; j < arg->n; j++)
    inc_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

int		dec(t_func_arg *arg)
{
  int		i;
  unsigned int	j;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  for (j = 0; j < arg->n; j++)
    dec_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

/*
** lsl rx, n
** Effectue un decalage a gauche de n bits des quartets 0 a P de rx.
** Les bits entrants sont nuls.
*/
int		lsl(t_func_arg *arg)
{
  int		i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  decal_left(arg->proc->reg[arg->rx - 1], arg->proc->p, arg->n);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

/*
** lsr rx, n
** Effectue un décalage à droite de n bits des quartets 0 a P de rx.
** Les bits entrants sont nuls.
*/
int		lsr(t_func_arg *arg)
{
  int		i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  decal_right(arg->proc->reg[arg->rx - 1], arg->proc->p, arg->n);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}
