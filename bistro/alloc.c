/*
** alloc.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 12:43:20 2002 bruno legros
** Last update Sat Nov  9 10:53:51 2002 bruno legros
*/

#include "bistro.h"

t_nbr	*alloc_nbr(t_base *base)
{
  t_nbr	*new;

  if (!(new = malloc(sizeof (t_nbr))))
    my_puterror(E_THE_WORLD_IS_OVER);
  new->base = base;
  if (!(new->nbr = malloc(1)))
    my_puterror(E_THE_WORLD_IS_OVER);
  new->nbr[0] = 0;
  new->nbr_len = 0;
  if (!(new->frac = malloc(1)))
    my_puterror(E_THE_WORLD_IS_OVER);
  new->frac[0] = base->base[1];
  new->frac_len = 1;
  new->negative = 0;
  new->makefree = 1;
  return new;
}

void	free_nbr(t_nbr *nbr)
{
  if (nbr->makefree)
    free(nbr->nbr);
  free(nbr->frac);
  free(nbr);
}
