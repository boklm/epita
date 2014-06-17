/*
** func4.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 11:20:38 2002 bruno legros
** Last update Sun Dec 22 18:47:42 2002 eric augustin
*/

#include "func4.h"

/*
** lp n
** Charge les 2 bits de poids faible de n dans P (P = n).
** Le fonctionnement est independant de P et n'affecte pas Z.
*/
int	lp(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  arg->proc->p = arg->n % 4;
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** fl rx, [ry]
** Charge les P + 1 quartets stockes a l'adresse PC + ry dans les quartets
** 0 a P de rx. ry est signe et utilise en entier.
** Le fonctionnement n'affecte pas Z.
*/
int	fl(t_func_arg *arg)
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
	 reg2int(arg->proc->reg[arg->ry - 1]) + 3 -
	 arg->proc->wbuf->place);
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
** write rx
** ecrit sur la sortie standard le caractere dont le code ASCII
** est contenu dans les 2 quartets de poids faible de rx.
** Le fonctionnement est independant de P et n'affecte pas Z.
*/
int	my_write2(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  if (!(arg->vm->flags & BONBON))
    if (write(STDOUT_FILENO, &(arg->proc->reg[arg->rx - 1][1]), 1) < 0)
      exit(1);
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

static int	put_in_rx(t_func_arg *arg, int stat)
{
  int2reg(arg->proc->reg[arg->rx - 1], stat);
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

static int	get_nb_player(t_func_arg *arg)
{
  int		i, p;

  for (p = i = 0; i < 15; i++)
    if (arg->vm->proc_per_player[i])
      p++;
  return p;
}

static int	my_stat2(t_func_arg *arg)
{
  if (arg->n == 6)
    return put_in_rx(arg, arg->vm->nb_cycles / 256);
  if (arg->n == 7)
    return put_in_rx(arg, 42);
  if (arg->n == 8)
    return put_in_rx(arg, get_nb_player(arg));
  if (arg->n == 9)
    return put_in_rx(arg, arg->proc->num);
  if (arg->n == 10)
    return put_in_rx(arg, arg->vm->max_proc);
  if (arg->n == 11)
    return put_in_rx(arg, arg->vm->proc_per_player[arg->proc->num - 1]);
  if (arg->n == 12)
    return put_in_rx(arg, arg->vm->nb_players);
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}

/*
** stat rx, n
** Charge dans rx entier la valeur du compteur n (see Statistiques).
** Le fonctionnement est independant de P et n'affecte pas Z.
** 0    Renvoie la constante EPOCH.
** 1    Renvoie la constante CYCLES_DELTA.
** 2    Renvoie la valeur actuelle de CYCLES_TO_DEATH.
** 3    Renvoie la taille de la memoire en quartets.
** 4    Renvoie la valeur de IDX_MOD.
** 5    Renvoie les 16 bits de poids faible du compteur de cycles.
** 6    Renvoie les 16 bits de poids fort du compteur de cycles.
** 7    Renvoie 42.
** 8    Renvoie le nombre de joueurs de la partie.
** 9    Renvoie le numero du joueur qui possede le processeur qui fait le stat.
** 10   Renvoie le nombre maximum de processeurs par joueur.
** 11   Renvoie le nombre de processeurs courant pour le joueur qui possede
**      le processeur qui fait le stat.
** 12   Renvoie le nombre initial de joueurs.
** 13, 14, 15  Ne sont pas modifies par l'instruction stat.
*/
int	my_stat(t_func_arg *arg)
{
  if (!arg || !arg->proc || !arg->vm)
    return 2;
  if (arg->rx < 1 || arg->rx > 16 || arg->n > 15)
    return 1;
  if (!arg->n)
    return put_in_rx(arg, arg->vm->epoch);
  if (arg->n == 1)
    return put_in_rx(arg, arg->vm->delta);
  if (arg->n == 2)
    return put_in_rx(arg, arg->vm->c_to_d);
  if (arg->n == 3)
    return put_in_rx(arg, arg->vm->size);
  if (arg->n == 4)
    return put_in_rx(arg, arg->vm->idx_mod);
  if (arg->n == 5)
    return put_in_rx(arg, arg->vm->nb_cycles % 256);
  return my_stat2(arg);
}

/*
** lc rx, n
** Charge n dans les 2 quartets de poids faible de rx et propage
** le bit de signe de ces 2 quartets dans les 2 quartets de poids fort de rx.
** Le fonctionnement est ind?pendant de P et n'affecte pas Z.
*/
int	lc(t_func_arg *arg)
{
  if (!arg || !arg->proc)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  int2reg(arg->proc->reg[arg->rx - 1], arg->n % 256);
  if (arg->proc->reg[arg->rx - 1][1] & 0x80)
    arg->proc->reg[arg->rx - 1][0] = 0xff;
  arg->proc->cur_work = WAIT_AFTER;
  arg->proc->rw->delay = 0;
  return 0;
}
