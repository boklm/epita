/*
** func5.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 16:29:08 2002 bruno legros
** Last update Sat Dec 21 11:17:37 2002 eric augustin
*/

#include "func5.h"

/*
** push rx
** Empile rx entier dans la pile du processeur.
** Le fonctionnement est independant de P et n'affecte pas Z.
*/
int	push(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->stack[arg->proc->stack_p][0] = arg->proc->reg[arg->rx - 1][0];
  arg->proc->stack[arg->proc->stack_p][1] = arg->proc->reg[arg->rx - 1][1];
  arg->proc->stack_p = (arg->proc->stack_p + 1) % 16;
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** pop rx
** Depile une valeur de la pile du processeur et la stocke dans rx.
** Le fonctionnement est independant de P et n'affecte pas Z.
*/
int	pop(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->stack_p = (arg->proc->stack_p - 1) % 16;
  arg->proc->reg[arg->rx - 1][0] = arg->proc->stack[arg->proc->stack_p][0];
  arg->proc->reg[arg->rx - 1][1] = arg->proc->stack[arg->proc->stack_p][1];
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** neg rx, ry
** Calcule la negation arithmetique (complement a 2) des quartets 0 a P
** de ry et stocke le resultat dans les quartets 0 a P de rx.
*/
int	neg(t_func_arg *arg)
{
  int	i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  for (arg->proc->z = 1, i = 3; 3 - i <= arg->proc->p; i--)
    {
      arg->proc->reg[arg->rx - 1][i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      arg->proc->reg[arg->rx - 1][i / 2] |=
	(~(arg->proc->reg[arg->ry - 1][i / 2]) & ((i % 2) ? 0x0f : 0xf0));
    }
  inc_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

/*
** add rx, ry
** Additionne les quartets 0 a P de ry a ceux de rx et stocke le
** resultat dans les quartets 0 a P de rx (rx = rx + ry).
*/
int		add(t_func_arg *arg)
{
  int		i, ry;
  unsigned char	tmp;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  arg->proc->z = 1;
  for (ry = 0, i = 3 - arg->proc->p; i < 4; i++)
    {
      ry *= 16;
      tmp = arg->proc->reg[arg->ry - 1][i / 2];
      if (!(i % 2))
	tmp >>= 4;
      tmp &= 0x0f;
      ry += tmp;
    }
  for (i = 0; i < ry; i++)
    inc_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

/*
** sub rx, ry
** Soustrait les quartets 0 a P de ry de ceux de rx et stocke
** le resultat dans les quartets 0 a P de rx (rx = rx - ry).
*/
int		sub(t_func_arg *arg)
{
  int		i, ry;
  unsigned char	tmp;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->ry < 1 || arg->ry > 16)
    return 1;
  arg->proc->z = 1;
  for (ry = 0, i = 3 - arg->proc->p; i < 4; i++)
    {
      ry *= 16;
      tmp = arg->proc->reg[arg->ry - 1][i / 2];
      if (!(i % 2))
	tmp >>= 4;
      tmp &= 0x0f;
      ry += tmp;
    }
  for (i = 0; i < ry; i++)
    dec_qrt(arg->proc->reg[arg->rx - 1], arg->proc->p);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}
