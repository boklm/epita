/*
** func7.c for corewar in /u/a1/august_e/corewar/vm/functions
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:07:25 2002 eric augustin
** Last update Sun Dec 22 16:07:26 2002 eric augustin
*/
#include "func7.h"

static void	get_dec(long int *dec, unsigned char r[2], char p)
{
  int		i;
  unsigned char	tmp;

  *dec = 0;
  for (i = 3 - p; i < 4; i++)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      *dec <<= 4;
      *dec |= tmp & 0x0f;
    }
}

static void	my_rol(unsigned char r[2], char p, unsigned int n)
{
  int		i;
  unsigned char	tmp;
  long int	dec;

  get_dec(&dec, r, p);
  n %= (p + 1) * 4;
  dec <<= n;
  for (i = 3; 3 - i <= p; i--)
    {
      tmp = dec & 0x0f;
      dec >>= 4;
      if (!(i % 2))
	tmp <<= 4;
      r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
    }
  for (i = 3; 3 - i <= p; i--)
    {
      tmp = dec & 0x0f;
      dec >>= 4;
      if (!(i % 2))
	tmp <<= 4;
      r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
    }
}

/*
** rol rx, n
** Effectue une rotation vers la gauche de n bits des quartets 0 a P de rx.
** L'instruction ror qui effectue une rotation à droite n'existe pas car
** on peut la simuler grace a un rol avec une valeur appropriée de n.
*/
int		rol(t_func_arg *arg)
{
  int		i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  my_rol(arg->proc->reg[arg->rx - 1], arg->proc->p, arg->n);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}

static void	ar_decal_right(unsigned char r[2], char p, unsigned int n)
{
  int		i;
  unsigned char	tmp;
  long int	dec;

  dec = 0;
  for (i = 3 - p; i < 4; i++)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      if ((i == 3 - p) && (tmp & 0x08))
	dec |= 0xffffffff;
      dec <<= 4;
      dec |= tmp & 0x0f;
    }
  dec >>= (n > 16) ? 16 : n;
  for (i = 3; 3 - i <= p; i--)
    {
      tmp = dec & 0x0f;
      dec >>= 4;
      if (!(i % 2))
	tmp <<= 4;
      r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
    }
}

/*
** asr rx, n
** Effectue un décalage arithmétique à droite de n bits des quartets 0 a P
** de rx. Ce décalage a pour caracteristique de faire entrer des bits
** identiques au bit de signe (conservation du signe).
*/
int		asr(t_func_arg *arg)
{
  int		i;

  if (!arg || !arg->proc || arg->proc->p > 3 || arg->proc->p < 0)
    return 2;
  if (arg->rx < 1 || arg->rx > 16)
    return 1;
  arg->proc->z = 1;
  ar_decal_right(arg->proc->reg[arg->rx - 1], arg->proc->p, arg->n);
  for (i = 3; 3 - i <= arg->proc->p; i--)
    if (arg->proc->reg[arg->rx - 1][i / 2] & ((i % 2) ? 0x0f : 0xf0))
      arg->proc->z = 0;
  arg->proc->rw->delay = arg->proc->p;
  arg->proc->cur_work = WAIT_AFTER;
  return 0;
}
