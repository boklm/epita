/*
** div.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 15:53:56 2002 bruno legros
** Last update Sun Nov 10 12:40:10 2002 bruno legros
*/

#include "bistro.h"

static void	test_div0(t_nbr *n2)
{
  t_nbr		*zero;

  zero = alloc_nbr(n2->base);
  zero->nbr[0] = n2->base->base[0];
  zero->nbr_len = 1;
  if (!nbr_cmp(n2, zero, 0))
    {
      my_putstr(E_ARITH);
      exit(1);
    }
  free_nbr(zero);
}

static t_nbr	*my_div2(t_nbr *n1, t_nbr *n2, t_nbr *res)
{
  t_nbr		*temp;
  t_mul		nb1, nb2;

  nb1.nbr = n1->frac;
  nb1.nbr_len = n1->frac_len;
  nb2.nbr = n2->nbr;
  nb2.nbr_len = n2->nbr_len;
  temp = mul_temp(&nb1, &nb2, n1->base);
  res->frac = temp->nbr;
  res->frac_len = temp->nbr_len;
  free(temp->frac);
  free(temp);
  res->negative = ((n1->negative ? 1 : 0) + (n2->negative ? 1 : 0)) % 2;
  return res;
}

t_nbr	*my_div(t_nbr *n1, t_nbr *n2)
{
  t_nbr	*res, *temp;
  t_mul	nb1, nb2;

  test_div0(n2);
  nb1.nbr = n1->nbr;
  nb1.nbr_len = n1->nbr_len;
  nb2.nbr = n2->frac;
  nb2.nbr_len = n2->frac_len;
  temp = mul_temp(&nb1, &nb2, n1->base);
  if (!(res = malloc(sizeof (t_nbr))))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->base = n1->base;
  res->nbr = temp->nbr;
  res->nbr_len = temp->nbr_len;
  res->makefree = 1;
  free(temp->frac);
  free(temp);
  return (my_div2(n1, n2, res));
}

static t_nbr	*add_un(t_nbr *quot)
{
  t_nbr		*un, *temp;

  un = alloc_nbr(quot->base);
  un->nbr[0] = quot->base->base[1];
  un->nbr_len = 1;
  temp = add(quot, un);
  free_nbr(quot);
  free_nbr(un);
  return temp;
}

static void	process(t_nbr *frac, t_nbr **quot, t_nbr **rest)
{
  t_nbr		*tmp2;

  tmp2 = sub(*rest, frac);
  free_nbr(*rest);
  *rest = tmp2;
  tmp2 = add_un(*quot);
  *quot = tmp2;
}

static void	div_ent_real(t_nbr *n, t_nbr **quot, t_nbr **rest)
{
  t_nbr		*frac;
  int		pos;

  frac = alloc_nbr(n->base);
  frac->nbr = n->frac;
  frac->nbr_len = n->frac_len;
  if (n->frac_len > 1)
    if (!((*rest)->nbr = realloc((*rest)->nbr, n->frac_len - 1)))
      my_puterror(E_THE_WORLD_IS_OVER);
  my_strncpy((*rest)->nbr, n->nbr, n->frac_len - 1);
  (*rest)->nbr_len = n->frac_len - 1;
  for (pos = (*rest)->nbr_len; pos < n->nbr_len; pos++)
    {
      if (!((*rest)->nbr = realloc((*rest)->nbr, ++(*rest)->nbr_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      (*rest)->nbr[(*rest)->nbr_len - 1] = n->nbr[pos];
      if (!((*quot)->nbr = realloc((*quot)->nbr, ++(*quot)->nbr_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      (*quot)->nbr[(*quot)->nbr_len - 1] = (*quot)->base->base[0];
      while (nbr_cmp(*rest, frac, 0) >= 0)
	process(frac, quot, rest);
    }
  free(frac->frac);
  free(frac);
}

t_nbr_2		*div_ent(t_nbr *n1, t_nbr *n2)
{
  t_nbr_2	*res;
  t_nbr		*rest, *quot, *n;

  test_div0(n2);
  n = my_div(n1, n2);
  rest = alloc_nbr(n1->base);
  quot = alloc_nbr(n1->base);
  check_zero(n, 0);
  check_zero(n, 1);
  if (n->frac_len > n->nbr_len)
    {
      quot->nbr[0] = n->base->base[0];
      quot->nbr_len = 1;
      if (!(rest->nbr = realloc(rest->nbr, rest->nbr_len = n->nbr_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      my_strncpy(rest->nbr, n->nbr, n->nbr_len);
    }
  else
    div_ent_real(n, &quot, &rest);
  if (!(res = malloc(sizeof (t_nbr_2))))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->quot = quot;
  res->rest = rest;
  res->quot->negative = n->negative;
  free_nbr(n);
  return res;
}
