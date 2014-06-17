/*
** mul.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 12:38:03 2002 bruno legros
** Last update Sun Nov 10 00:35:07 2002 bruno legros
*/

#include "bistro.h"

static t_nbr	*mul_1(unsigned char c, t_mul *n, t_base *base)
{
  int		i, b_c, k;
  int		mul, ret;
  t_nbr		*res;

  b_c = bas(c, base);
  res = alloc_nbr(base);
  k = n->nbr_len;
  if (!(res->nbr = realloc(res->nbr, k + 1)))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->nbr_len = k + 1;
  for (ret = 0, i = n->nbr_len - 1; i >= 0 || ret; i--, k--)
    {
      mul = b_c * bas((i < 0) ? base->base[0] : n->nbr[i], base) + ret;
      res->nbr[k] = base->base[mul % base->base_len];
      ret = (mul >= base->base_len) ? (mul / base->base_len) : 0;
    }
  if (k != -1)
    res->nbr[0] = res->base->base[0];
  return res;
}

t_nbr	*mul_temp(t_mul *nb1, t_mul *nb2, t_base *base)
{
  int	i, b;
  t_nbr	*res, *temp, **tab;

  if (nb1->nbr_len < nb2->nbr_len)
    return (mul_temp(nb2, nb1, base));
  tab = malloc(base->base_len * sizeof (t_nbr *));
  for (i = 0; i < base->base_len; i++)
    tab[i] = NULL;
  res = alloc_nbr(base);
  for (i = 0; i < nb2->nbr_len; i++)
    {
      if (!(res->nbr = realloc(res->nbr, ++res->nbr_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      res->nbr[res->nbr_len - 1] = base->base[0];
      if (!tab[b = bas(nb2->nbr[i], base)])
	temp = add(res, tab[b] = mul_1(nb2->nbr[i], nb1, base));
      else
	temp = add(res, tab[b]);
      free_nbr(res);
      res = temp;
    }
  for (i = 0; i < base->base_len; i++)
    if (tab[i])
      free_nbr(tab[i]);
  free(tab);
  return res;
}

static void	affect(t_mul *nb1, t_nbr *n1, t_mul *nb2, t_nbr *n2)
{
  nb1->nbr = n1->nbr;
  nb1->nbr_len = n1->nbr_len;
  nb2->nbr = n2->nbr;
  nb2->nbr_len = n2->nbr_len;
}

t_nbr	*mul(t_nbr *n1, t_nbr *n2)
{
  t_nbr	*res, *temp;
  t_mul	nb1, nb2;

  if (!(res = malloc(sizeof (t_nbr))))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->base = n1->base;
  res->makefree = 1;
  affect(&nb1, n1, &nb2, n2);
  temp = mul_temp(&nb1, &nb2, n1->base);
  res->nbr = temp->nbr;
  res->nbr_len = temp->nbr_len;
  free(temp->frac);
  free(temp);
  nb1.nbr = n1->frac;
  nb1.nbr_len = n1->frac_len;
  nb2.nbr = n2->frac;
  nb2.nbr_len = n2->frac_len;
  temp = mul_temp(&nb1, &nb2, n1->base);
  res->frac = temp->nbr;
  res->frac_len = temp->nbr_len;
  free(temp->frac);
  free(temp);
  res->negative = ((n1->negative ? 1 : 0) + (n2->negative ? 1 : 0)) % 2;
  return res;
}
