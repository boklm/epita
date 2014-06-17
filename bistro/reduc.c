/*
** reduc.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 12:43:31 2002 bruno legros
** Last update Sun Nov 10 13:12:37 2002 bruno legros
*/

#include "bistro.h"

static void	process(t_nbr **a, t_nbr **b, t_nbr **rest)
{
  t_nbr_2	*nbr;

  nbr = div_ent(*a, *b);
  *rest = nbr->rest;
  free_nbr(nbr->quot);
  free(nbr);
  free_nbr(*a);
  *a = *b;
  *b = *rest;
}

static t_nbr	*my_pgcd(t_nbr *n)
{
  t_nbr		*rest, *zero;
  t_nbr		*a, *b;

  (zero = alloc_nbr(n->base))->nbr[0] = n->base->base[0];
  zero->nbr_len = 1;
  (rest = alloc_nbr(n->base))->nbr[0] = rest->frac[0];
  rest->nbr_len++;
  a = alloc_nbr(n->base);
  if (!(a->nbr = realloc(a->nbr, a->nbr_len = n->nbr_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  my_strncpy(a->nbr, n->nbr, a->nbr_len);
  b = alloc_nbr(n->base);
  if (!(b->nbr = realloc(b->nbr, b->nbr_len = n->frac_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  my_strncpy(b->nbr, n->frac, n->frac_len);
  while (nbr_cmp(rest, zero, 0))
    process(&a, &b, &rest);
  free_nbr(b);
  free_nbr(zero);
  return a;
}

static t_nbr	*alloc_reduc(t_nbr *n, int frac)
{
  t_nbr		*temp;

  temp = alloc_nbr(n->base);
  if (!frac)
    {
      if (!(temp->nbr = realloc(temp->nbr, temp->nbr_len = n->nbr_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      my_strncpy(temp->nbr, n->nbr, temp->nbr_len = n->nbr_len);
    }
  else
    {
      if (!(temp->nbr = realloc(temp->nbr, temp->nbr_len = n->frac_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      my_strncpy(temp->nbr, n->frac, temp->nbr_len = n->frac_len);
    }
  return temp;
}

static t_nbr	*div_ent_reduc(t_nbr *n, t_nbr *pgcd)
{
  t_nbr_2	*nbr;
  t_nbr		*quot;

  nbr = div_ent(n, pgcd);
  quot = nbr->quot;
  free_nbr(nbr->rest);
  free(nbr);
  return quot;
}

static t_nbr	*real_reduc(t_nbr *n)
{
  t_nbr		*pgcd, *temp, *nom, *denom;

  if (!((pgcd = my_pgcd(n))->nbr_len == 1 && *pgcd->nbr == *n->base->base))
    {
      nom = alloc_reduc(n, 0);
      denom = alloc_reduc(n, 1);
      temp = div_ent_reduc(nom, pgcd);
      if (n->makefree)
	free(n->nbr);
      n->nbr = temp->nbr;
      n->nbr_len = temp->nbr_len;
      free(temp->frac);
      free(temp);
      free_nbr(nom);
      temp = div_ent_reduc(denom, pgcd);
      free(n->frac);
      n->frac = temp->nbr;
      n->frac_len = temp->nbr_len;
      free(temp->frac);
      free(temp);
      free_nbr(denom);
    }
  free_nbr(pgcd);
  check_zero(n, 0);
  check_zero(n, 1);
  return n;
}

t_nbr	*reduc(t_nbr *n)
{
  t_nbr	*un;

  un = alloc_nbr(n->base);
  un->nbr[0] = n->base->base[1];
  un->nbr_len++;
  if (nbr_cmp(un, n, 1))
    {
      free_nbr(un);
      return (real_reduc(n));
    }
  check_zero(n, 0);
  free_nbr(un);
  return n;
}
